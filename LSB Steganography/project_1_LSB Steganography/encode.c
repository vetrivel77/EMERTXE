#include <stdio.h>
#include "encode.h"
#include "types.h"
#include <string.h>
#include "common.h"

/* Function definition for check operation type */
OperationType check_operation_type(char *argv[])
{
    if (strcmp(argv[1], "-e") == 0)
        return e_encode;
    if (strcmp(argv[1], "-d") == 0)
        return e_decode;
    else
        return e_unsupported;
}

/* Function Definitions */
/* Get image size
 * Input: Image file ptr
 * Output: width * height * bytes per pixel (3 in our case)
 * Description: In BMP Image, width is stored in offset 18,
 * and height after that. size is 4 bytes
 */
uint get_image_size_for_bmp(FILE *fptr_image)
{
    uint width, height;
    // Seek to 18th byte
    fseek(fptr_image, 18, SEEK_SET);

    // Read the width (an int)
    fread(&width, sizeof(int), 1, fptr_image);
    printf("width = %u\n", width);

    // Read the height (an int)
    fread(&height, sizeof(int), 1, fptr_image);
    printf("height = %u\n", height);

    // Return image capacity
    return width * height * 3;
}

/* 
 * Get File pointers for i/p and o/p files
 * Inputs: Src Image file, Secret file and
 * Stego Image file
 * Output: FILE pointer for above files
 * Return Value: e_success or e_failure, on file errors
 */
Status open_files(EncodeInfo *encInfo)
{
    // Src Image file
    encInfo->fptr_src_image = fopen(encInfo->src_image_fname, "r");
    // Do Error handling
    if (encInfo->fptr_src_image == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->src_image_fname);

        return e_failure;
    }

    // Secret file
    encInfo->fptr_secret = fopen(encInfo->secret_fname, "r");
    // Do Error handling
    if (encInfo->fptr_secret == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->secret_fname);

        return e_failure;
    }

    // Stego Image file
    encInfo->fptr_stego_image = fopen(encInfo->stego_image_fname, "w");
    // Do Error handling
    if (encInfo->fptr_stego_image == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->stego_image_fname);

        return e_failure;
    }

    // No failure return e_success
    return e_success;
}

// Function definition for read and validate encode args
Status read_and_validate_encode_args(char *argv[], EncodeInfo *encInfo)
{
    // If condition to check argv[2] is .bmp or not 
    if (strcmp(strstr(argv[2], "."), ".bmp") == 0)
    {
        encInfo->src_image_fname = argv[2];
    }
    else
        return e_failure;

    if (strcmp(strstr(argv[3], "."), ".txt") == 0)
    {
        encInfo->secret_fname = argv[3];
    }
    else
        return e_failure;

    if (argv[4] != NULL)
        encInfo->stego_image_fname = argv[4];
    else
        encInfo->stego_image_fname = "stego.bmp";
    return e_success;
}

// Function definition for check capacity
Status check_capacity(EncodeInfo *encInfo)
{
    encInfo->image_capacity = get_image_size_for_bmp(encInfo->fptr_src_image);
    encInfo->size_secret_file = get_file_size(encInfo->fptr_secret);
    if (encInfo->image_capacity > ((strlen(MAGIC_STRING) + 4 + 4 + 4 + encInfo->size_secret_file) * 8))
        return e_success;
    else
        return e_failure;
}

// Function definition for getting file size 
long get_file_size(FILE *fptr)
{
    fseek(fptr, 0, SEEK_END);
    return ftell(fptr);
}

// Function definition for copying 1st 54 bytes header file
Status copy_bmp_header(FILE *fptr_src_image, FILE *fptr_dest_image)
{
    char str[54];

    // Setting pointer to point to 0th position 
    fseek(fptr_src_image, 0, SEEK_SET);

    // Reading 54 bytes from beautiful.bmp
    fread(str, 54, 1, fptr_src_image);

    // Writing 54 bytes to str
    fwrite(str, 54, 1, fptr_dest_image);
    return e_success;
}

// Function definition for encoding magic string
Status encode_magic_string(char *magic_string, EncodeInfo *encInfo)
{
    encode_data_to_image(magic_string, 2, encInfo->fptr_src_image, encInfo->fptr_stego_image, encInfo);
    return e_success;
}

// Function definition for Encode data to image
Status encode_data_to_image(char *data, int size, FILE *fptr_src_image, FILE *fptr_stego_image, EncodeInfo *encInfo)
{
    for (int i = 0; i < size; i++)
    {
        fread(encInfo->image_data, 8, 1, fptr_src_image);
        encode_byte_to_lsb(data[i], encInfo->image_data);
        fwrite(encInfo->image_data, 8, 1, fptr_stego_image);
    }

}

// Function definition for encode byte to lsb
Status encode_byte_to_lsb(char data, char *image_buffer)
{
    unsigned int mask = 0x80, i;
    for (i = 0; i < 8; i++)
    {
        image_buffer[i] = (image_buffer[i] & 0xFE) | ((data & mask) >> (7 - i));
        mask = mask >> 1;
    }
}

// Function definition for encode secret file extn size
Status encode_secret_file_extn_size(int size, FILE *fptr_src_image, FILE *fptr_stego_image)
{
    char str[32];
    fread (str, 32, 1, fptr_src_image);
    encode_size_to_lsb(size, str);
    fwrite(str, 32, 1, fptr_stego_image);
    return e_success;
}

// Function definition to encode size to lsb
Status encode_size_to_lsb(int size, char *image_buffer)
{
    unsigned int mask = 1 << 31, i;
    for (i = 0; i < 32; i++)
    {
        image_buffer[i] = (image_buffer[i] & 0xFE) | ((size & mask) >> (31 - i));
        mask = mask >> 1;
    }

}

// Function definition to encode secret file extn
Status encode_secret_file_extn(char *file_extn, EncodeInfo *encInfo)
{
    encode_data_to_image(file_extn, strlen(file_extn), encInfo->fptr_src_image, encInfo->fptr_stego_image, encInfo);
    return e_success;
}

// Function definition for encode secret file size
Status encode_secret_file_size(int size, EncodeInfo *encInfo)
{
    char str[32];
    fread (str, 32, 1, encInfo->fptr_src_image);
    encode_size_to_lsb(size, str);
    fwrite(str, 32, 1, encInfo->fptr_stego_image);
    return e_success;
}

// Function definition for encode secret file data
Status encode_secret_file_data(EncodeInfo *encInfo)
{
    fseek(encInfo->fptr_secret, 0, SEEK_SET);
    char str[encInfo->size_secret_file];
    fread(str, encInfo->size_secret_file, 1, encInfo->fptr_secret);
    encode_data_to_image(str, strlen(str), encInfo->fptr_src_image, encInfo->fptr_stego_image, encInfo);
    return e_success;
}

// Function definition for copying remaining data as it is
Status copy_remaining_img_data(FILE *fptr_src, FILE *fptr_dest)
{
    char ch;
    while ((fread(&ch, 1, 1, fptr_src)) > 0)
    {
        fwrite(&ch, 1, 1, fptr_dest);
    }
    return e_success;
}

// Function definition for do encoding called in main function
Status do_encoding(EncodeInfo *encInfo)
{
    if (open_files(encInfo) == e_success)
    {
        printf("Open files is a success\n");
        if (check_capacity(encInfo) == e_success)
        {
            printf("Check capacity is a success\n");
            if (copy_bmp_header(encInfo->fptr_src_image, encInfo->fptr_stego_image) == e_success)
            {
                printf("Copied bmp header successfully\n");
                if (encode_magic_string(MAGIC_STRING, encInfo) == e_success)
                {
                    printf("Encoded magic string successfully\n");
                    strcpy(encInfo->extn_secret_file, strstr(encInfo->secret_fname, "."));
                    if (encode_secret_file_extn_size(strlen(encInfo->extn_secret_file), encInfo->fptr_src_image, encInfo->fptr_stego_image) == e_success)
                    {
                        printf("Encoded secret file extn size successfully\n");
                        if (encode_secret_file_extn(encInfo->extn_secret_file, encInfo) == e_success)
                        {
                            printf("Encoded secret file extn successfully\n");
                            if (encode_secret_file_size(encInfo->size_secret_file, encInfo) == e_success)
                            {
                                printf("Encoded secret file size successfully\n");
                                if (encode_secret_file_data(encInfo) == e_success)
                                {
                                    printf("Encoded secret file data\n");
                                    if (copy_remaining_img_data(encInfo->fptr_src_image, encInfo->fptr_stego_image) == e_success)
                                    {
                                        printf("Copied remaining data successfully\n");
                                    }
                                    else
                                    {
                                        printf("Failed to copy remaining data successfully\n");
                                        return e_failure;
                                    }

                                }
                                else
                                {
                                    printf("Failed to encode secret file data\n");
                                    return e_failure;
                                }
                            }
                            else
                            {
                                printf("Failed to encode secret file size\n");
                                return e_failure;
                            }
                        }
                        else
                        {
                            printf("Failed to encode secret file extn\n");
                            return e_failure;
                        }
                    }
                    else
                    {
                        printf("Failed to encoded secret file extn size\n");
                        return e_failure;
                    }
                }
                else
                {
                    printf("Failed to encode magic string\n");
                    return e_failure;
                }
            }
            else
            {
                printf("Failed to copy bmp header\n");
                return e_failure;
            }
        }
        else
        {
            printf("Check capacity is a failure\n");
            return e_failure;
        }
    }
    else
    {
        printf("Open files is a failure\n");
        return e_failure;
    }
    return e_success;
}
