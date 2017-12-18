#ifndef KNX_FILE_STRING
#define KNX_FILE_STRING

char * getFileExtension(char *);    ///Return full extension. Does not include first '.'
char * getFilePath(char *);         ///Return file path ignoring file name and extensions
char * getFileName(char *, char);   /**Return file name, ignoring file path. Includes extensions if
                                       Second argument is non zero*/

#endif