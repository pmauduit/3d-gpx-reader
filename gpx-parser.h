#ifndef __GPX_PARSER_H
#define __GPX_PARSER_H

#include <string>
// tdgr stands for ThreeDimensionGpxReader
namespace tdgr {

  class GpxParser {
    private:
     std::string gpxPath;

    public:
     GpxParser();
     ~GpxParser();
  };
}


#endif // __GPX_PARSER_H
