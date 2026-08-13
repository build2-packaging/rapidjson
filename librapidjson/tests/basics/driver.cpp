#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

#undef NDEBUG
#include <cassert>

int main ()
{
  using namespace rapidjson;

  Document d;
  d.Parse ("{\"project\":\"rapidjson\",\"stars\":10}");
  assert (!d.HasParseError ());
  assert (d["stars"].GetInt () == 10);

  StringBuffer buf;
  Writer<StringBuffer> w (buf);
  d.Accept (w);
  assert (buf.GetSize () > 0);
}
