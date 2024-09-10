cmake_minimum_required(VERSION 3.16)
project(XML_2_JSON C)

include(FindPkgConfig)

pkg_check_modules(libxml-2.0 REQUIRED libxml-2.0)
message(STATUS "${libxml-2.0_INCLUDE_DIRS}")
message(STATUS "${libxml-2.0_LINK_LIBRARIES}")

pkg_check_modules(json-c REQUIRED json-c)
message(STATUS "${json-c_INCLUDE_DIRS}")
message(STATUS "${json-c_LINK_LIBRARIES}")


add_executable(xml2json main.c
                        init_xml_file.c
                        get_json_obj.c
                        log_json_obj.c)

target_include_directories(xml2json PRIVATE ${libxml-2.0_INCLUDE_DIRS})
target_link_libraries(xml2json PRIVATE ${libxml-2.0_LINK_LIBRARIES})

target_include_directories(xml2json PRIVATE ${json-c_INCLUDE_DIRS})
target_link_libraries(xml2json PRIVATE ${json-c_LINK_LIBRARIES})
