#ifndef DECODE_H
#define DECODE_H

#include "types.h" // Contains user defined types

/*
 * Structure to store information required for
 * decoding secret file to source Image
 * Info about output and intermediate data is
 * also stored
 */

#define MAX_SECRET_BUF_SIZE 1
#define MAX_IMAGE_BUF_SIZE (MAX_SECRET_BUF_SIZE * 8)

typedef struct _DecodeInfo
{
    /* Stego image Info */
    char *d_src_image_fname;
    FILE *fptr_d_src_image;

    char d_image_data[MAX_IMAGE_BUF_SIZE];
    char *magic_data;
    char *d_extn_secret_file;

    int size_secret_file;
    FILE *fptr_d_dest_image;

    char *d_secret_fname;
    FILE *fptr_d_secret;
} DecodeInfo;


/* Decoding Function Prototypes */

/* Read and validate decode args from argv */
Status_d read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo);

/* Perform the decoding */
Status_d do_decoding(DecodeInfo *decInfo);

/* Get File pointers for i/p and o/p files */
Status_d open_files_dec(DecodeInfo *decInfo);

/* Decode Magic String */
Status_d decode_magic_string(DecodeInfo *decInfo);

/* Decode data from image */
Status_d decode_data_from_image(int size, FILE *fptr_d_src_image,
        DecodeInfo *decInfo);

/* Decode byte from lsb */
Status_d decode_byte_from_lsb(char *data, char *image_buffer);

/* Decode file extn size */ 
Status_d decode_file_extn_size (int size, FILE *fptr_d_src_image);

/* Decode size from lsb */
Status_d decode_size_from_lsb (char *buffer, int *size);

/* Decode secret file extn */
Status_d decode_secret_file_extn (char *file_ext, DecodeInfo *decInfo) ;

/* Decode extension data from image */
Status_d decode_extension_data_from_image ( int size, FILE *fptr_d_src_image, DecodeInfo *decInfo); 

/* Decode secret file size */
Status_d decode_secret_file_size (int file_size, DecodeInfo *decInfo);

/* Decode secret file data */
Status_d decode_secret_file_data (DecodeInfo *decInfo);
#endif
