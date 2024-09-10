#include "log_json_obj.h"

#include <stdio.h>

void log_json_result(json_object *obj, const char *search_tag)
{
  if (json_object_array_length(obj) > 0) {
    printf("xml nodes with tag name \"%s\" found:\n%s\n", search_tag, json_object_to_json_string_ext(obj, JSON_C_TO_STRING_PRETTY));
  } else {
    printf("No xml nodes with tag name \"%s\" found.\n", search_tag);
  }
}
