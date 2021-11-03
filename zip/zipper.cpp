#include "zipper.h"

Zipper::Zipper()
{

}

Zipper::~Zipper()
{

}

void Zipper::getInfo(const QStringList strList)
{
    std::ofstream finfo("info.txt");

    for(auto x:strList) //collecting files data
    {
        std::ifstream f(x.toStdString(),std::ios::binary | std::ios::ate);
        f.seekg(0,std::ios::end);
        size.push_back(f.tellg());

        files.push_back(x.toStdString());
        f.close();
    }

    for(int i=0;i<files.size();++i) //writing the collected data to info.txt
    {
        finfo<<size[i]<<" "<<get_file_name(files[i])<<" ";
    }
    finfo<<"\n";

    finfo.close();
}

int Zipper::inCompress()
{
    char byte[1];

    std::ifstream infoFile("info.txt",std::ios::binary);
    std::ofstream zipFile("bin.zipped",std::ios::binary);

    while (infoFile.read(byte,sizeof (byte))) //rewriting file info
    {
        zipFile.write(byte,sizeof (byte));
    }
    infoFile.close();

    for(auto x:files) //zipped
    {
        std::ifstream f(x,std::ios::binary);
        while (f.read(byte,sizeof (byte)))
        {
            zipFile.write(byte,sizeof(byte));
        }
    }

    zipFile.close();
    remove("info.txt");
    return 0;
}

int Zipper::outCompress(const std::string pathZipFile)
{
    std::ifstream zipFile(pathZipFile,std::ios::binary);
    std::string infoStr, tempInfo;
    std::vector<std::string> filesName;
    std::vector<int> filesSize;
    std::getline(zipFile,infoStr); //read a line with information about files
    int count=0;
    char byte[1];

    for(int i=0;i<infoStr.size();++i)//process the info line
    {
        if(infoStr[i]==' ')
        {
            if(count==0)
            {
                filesSize.push_back(std::stoi(tempInfo));
                count=1;
                tempInfo="";
            }
            else
            {
                filesName.push_back(tempInfo);
                count=0;
                tempInfo="";
            }
            continue;
        }
        else
        {
            tempInfo+=infoStr[i];
        }
    }

    for(int i=0;i<filesName.size();++i) //unzipped
    {
        std::ofstream f(filesName[i],std::ios::binary);
        for(int j=0;j<filesSize[i];++j)
        {
            zipFile.read(byte,sizeof (byte));
            f.write(byte,sizeof (byte));
        }
        f.close();
    }

    zipFile.close();
    return 0;
}

std::string Zipper::get_file_name(std::string fullPath) //separating the filename from the full path
{
    std::string nameFile;
    reverse(fullPath.begin(), fullPath.end());
    int findChar = fullPath.find('/');
    reverse(fullPath.begin(), fullPath.end());
    for(int i=fullPath.size()-findChar;i<fullPath.size();++i){
        nameFile+=fullPath[i];
    }
    return nameFile;
}
