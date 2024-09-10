#ifndef GET_JSON_OBJECT_H
#define GET_JSON_OBJECT_H

#include <libxml/parser.h>
#include <json-c/json.h>

json_object *get_json_result(const xmlDoc *doc, const char *search_tag);

#endif /* GET_JSON_OBJECT_H */
