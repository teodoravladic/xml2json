# XML2JSON
This project is designed to find specific xml nodes and parse it into json format.


# 1. Prerequisites
* [libxml2](https://github.com/GNOME/libxml2) library
* [json-c](https://github.com/json-c/json-c) library

# 2. Build
```bash
git clone https://github.com/teodoravladic/xml2json.git
cd xml2json
mkdir build && cd build && cmake .. && make
```

# 3. Run
This program requires 2 arguments, a xml file and a search tag, as follows:
```bash
./xml2json <xml-file> <search-tag>
```
