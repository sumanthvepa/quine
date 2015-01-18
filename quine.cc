#include <boost/algorithm/string/replace.hpp>
#include <iostream>
#include <string>

const char quote[] = {34, 0};
const char escaped_quote[] = {92, 34, 0};
const char linefeed[] = {10, 0};
const char linefeed_replacement[] = {92, 'n', 34, 10, 32, 32, 32, 32, 34, 0};

std::string myself
  = "#include <boost/algorithm/string/replace.hpp>\n"
    "#include <iostream>\n"
    "#include <string>\n"
    "\n"
    "const char quote[] = {34, 0};\n"
    "const char escaped_quote[] = {92, 34, 0};\n"
    "const char linefeed[] = {10, 0};\n"
    "const char linefeed_replacement[] = {92, 'n', 34, 10, 32, 32, 32, 32, 34, 0};\n"
    "\n"
    "std::string myself\n"
    "  = MYSELF;\n"
    "\n"
    "std::string escape_quote(const std::string& input)\n"
    "{\n"
    "  return boost::replace_all_copy(input, quote, escaped_quote);\n"
    "}\n"
    "\n"
    "std::string newline_to_indent_strings(const std::string& input)\n"
    "{\n"
    "  return boost::replace_all_copy(input, linefeed, linefeed_replacement);\n"
    "}\n"
    "\n"
    "std::string quotify(const std::string& input)\n"
    "{\n"
    "  return std::string(quote)\n"
    "    + newline_to_indent_strings(escape_quote(input))\n"
    "    + std::string(quote);\n"
    "}\n"
    "\n"
    "std::string self_substitute(\n"
    "  const std::string& input,\n"
    "  const std::string& pattern)\n"
    "{\n"
    "  std::string quotified_input = quotify(input);\n"
    "  size_t pos = input.find(pattern);\n"
    "  size_t len = pattern.length();\n"
    "  std::string output = input;\n"
    "  output.replace(pos, len, quotified_input);\n"
    "  return output;\n"
    "}\n"
    "\n"
    "int main(int argc, const char *argv[])\n"
    "{\n"
    "  std::cout << self_substitute(myself, \"MYSELF\") << std::endl;\n"
    "  return 0;\n"
    "}";

std::string escape_quote(const std::string& input)
{
  return boost::replace_all_copy(input, quote, escaped_quote);
}

std::string newline_to_indent_strings(const std::string& input)
{
  return boost::replace_all_copy(input, linefeed, linefeed_replacement);
}

std::string quotify(const std::string& input)
{
  return std::string(quote)
    + newline_to_indent_strings(escape_quote(input))
    + std::string(quote);
}

std::string self_substitute(
  const std::string& input,
  const std::string& pattern)
{
  std::string quotified_input = quotify(input);
  size_t pos = input.find(pattern);
  size_t len = pattern.length();
  std::string output = input;
  output.replace(pos, len, quotified_input);
  return output;
}

int main(int argc, const char *argv[])
{
  std::cout << self_substitute(myself, "MYSELF") << std::endl;
  return 0;
}
