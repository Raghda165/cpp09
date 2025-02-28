bool include_pipe(std::string &line)
{
    size_t pos = line.find('|');
    if(pos== std::string::npos)
        return(0);
    return(1);
}

void parse(std::string &line)
{
    if(include_pipe(line))
    {
        
    }

}