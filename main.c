#include "init_xml_file.h"
#include "get_json_obj.h"
#include "log_json_obj.h"

int main(int argc, char *argv[])
{
  if(argc != 3){
    fprintf(stderr, "Help: %s <xml-file> <search-tag>\n", argv[0]);
    return EXIT_FAILURE;
  }

  const char *filename = argv[1];
  const char *search_tag = argv[2];

  // Initialize the xml file
  xmlDoc *doc = init_xml_file(filename);

  // Find the pattern and save in json object
  json_object *json_result = get_json_result(doc, search_tag);

  // Print the json result
  log_json_result(json_result, search_tag);

  // Free the memory
  json_object_put(json_result);
  xmlFreeDoc(doc);
  xmlCleanupParser();

  return EXIT_SUCCESS;
}
