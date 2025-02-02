#include "cmd-args.h"
#include "directory.h"

static bool isCmdArg(const std::string& arg)
{
  return arg.substr(0, 2) == "--";
}

CmdArgs::CmdArgs(int argc, char* argv[]) : _path(Directory::cwd()), _watch(false), _help(false)
{
  for (int i=1; i<argc; ++i)
  {
    std::string arg(argv[i]);

    if (!isCmdArg(arg))
      this->_path = Directory::absolute(arg);
    else
      parseArg(arg);
  }
}

void CmdArgs::parseArg(const std::string& arg)
{
  if (arg == "--watch")
    this->_watch = true;

  if (arg == "--help")
    this->_help = true;
}

const std::string& CmdArgs::path()
{
  return this->_path;
}

bool CmdArgs::watch()
{
  return this->_watch;
}

bool CmdArgs::help()
{
  return this->_help;
}
