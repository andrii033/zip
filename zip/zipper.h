#ifndef ZIPPER_H
#define ZIPPER_H

#include <QFileDialog>
#include <QDebug>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class Zipper
{
private:
    std::vector<std::string> files; //list of files to archive
    std::vector<int> size; //sizes of archived files
public:
    Zipper();
    ~Zipper();
    void getInfo(const QStringList strList); //files data
    int inCompress();
    int outCompress(const std::string pathZipFile);
    std::string get_file_name(std::string fullPath);
};

#endif // ZIPPER_H
