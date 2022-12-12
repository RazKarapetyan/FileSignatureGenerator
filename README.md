# FileSignatureGenerator under MacOSX (TATO <3 )
CLI tool to generate the signature of the specified file.
### Prepare development environment
1. Install required libs 
   ```bash
   brew install boost 

3. Clone the repository
   ```bash
   # for ssh
   git clone git@github.com:RazKarapetyan/FileSignatureGenerator.git

4. Configure and build the project
   ```bash
   cd FileSignatureGenerator #if not in it already
   mkdir build
   cd build
   cmake .. 
   cmake --build .
   ```
5. Run the app
    ```bash
    ./app/FileSignatureGenerator 
    App Usage:
        -h [ --help ]         Display help message
        --input-file arg      Input file path [required]
        --output-file arg     Output file path [required]
        --block-size arg (=1) File block size in MB

The signature is generated as follows: the source file is divided into blocks equal to
(fixed) length (if the file size is not a multiple of the block size, the last fragment may
be less than or padded with zeros to the size of a full block). 
For each block is calculated the hash value of the function and is added to the output signature file.

Interface: command line, which specifies:
* Path to input file
* Path to the output file
* Block size (default, 1 Mb)
