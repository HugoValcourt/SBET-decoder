#ifndef QTSBETPRINTER_H
#define QTSBETPRINTER_H

#include <QFile>
#include "../../SbetPrinter.hpp"

class QtSbetPrinter : public SbetPrinter
{
public:
    QtSbetPrinter(std::string outFilename);
    ~QtSbetPrinter();

    //Overload
    void processEntry(SbetEntry * entry);
    bool OpenFile();
    void CloseFile();

private:
    std::string outFilename;
    FILE *file;
};


#endif // QTSBETPRINTER_H
