#include "get_json_obj.h"

#include <string.h>

static void parse_xml_node(xmlNode *node, json_object *obj)
{
  for (xmlNode *cur_child = node; cur_child; cur_child = cur_child->next){
    if(cur_child->type == XML_ELEMENT_NODE){
      if(xmlChildElementCount(cur_child) == 0){
        json_object_object_add(obj,
                               (const char *)cur_child->name,
                               json_object_new_string((const char *)xmlNodeGetContent(cur_child)));
      } else {
        json_object *child_obj = json_object_new_object();
        parse_xml_node(cur_child->children, child_obj);
        json_object_object_add(obj, (const char *)cur_child->name, child_obj);
      }
    }
  }
}

static void find_xml_search_tag(xmlNode *node, const char *search_tag, json_object *result_array)
{
  for (xmlNode *cur_node = node; cur_node; cur_node = cur_node->next){
    if(cur_node->type == XML_ELEMENT_NODE){
      if(strcmp((const char*)cur_node->name, search_tag) == 0){
        json_object *parent_obj = json_object_new_object();
        json_object *children_obj = json_object_new_object();
        parse_xml_node(cur_node->children, children_obj);
        json_object_object_add(parent_obj, (const char *)cur_node->name, children_obj);
        json_object_array_add(result_array, parent_obj);
      } else {
        find_xml_search_tag(cur_node->children, search_tag, result_array);
      }
    }
  }
}

json_object *get_json_result(const xmlDoc *doc, const char *search_tag)
{
  xmlNode *root_element = xmlDocGetRootElement(doc);

  json_object *json_result = json_object_new_array();
  find_xml_search_tag(root_element->children, search_tag, json_result);

  return json_result;
}
