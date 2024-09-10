#include "init_xml_file.h"

#include <assert.h>
#include <stdio.h>
#include <unistd.h>

static void add_root_xml(const char *input_file, const char *output_file)
{
  FILE *in_fp = fopen(input_file, "r");

  FILE *out_fp = fopen(output_file, "w");
  if (out_fp == NULL) {
    assert(false && "Error opening output file");
    fclose(in_fp);
    return;
  }

  fprintf(out_fp, "<data>\n");
  
  char ch;
  while ((ch = fgetc(in_fp)) != EOF) {
    fputc(ch, out_fp);
  }

  fprintf(out_fp, "\n</data>");

  fclose(in_fp);
  fclose(out_fp);
}

xmlDoc *init_xml_file(const char *filename)
{
  assert(access(filename, F_OK) == 0 && "Input file does not exist\n");

  xmlDoc *doc = xmlReadFile(filename, NULL, 0);

  if(doc == NULL){
    const char new_filename[] = "temp_file.xml";
    printf("The \"%s\" could not be parsed correctly. Creating \"%s\" with the root element.\n\n", filename, new_filename);
    add_root_xml(filename, new_filename);
    doc = xmlReadFile(new_filename, NULL, 0);
  }

  return doc;
}
