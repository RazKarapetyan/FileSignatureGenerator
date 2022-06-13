# FileSignatureGenerator
CLI tool to generate the signature of the specified file.

The signature is generated as follows: the source file is divided into blocks equal to
(fixed) length (if the file size is not a multiple of the block size, the last fragment may
be less than or padded with zeros to the size of a full block). 
For each block is calculated the hash value of the function and is added to the output signature file.

Interface: command line, which specifies:
* Path to input file
* Path to the output file
* Block size (default, 1 Mb)
