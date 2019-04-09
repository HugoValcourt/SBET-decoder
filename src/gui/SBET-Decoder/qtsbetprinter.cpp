#ifndef QTSBETPROCESSOR_CPP
#define QTSBETPROCESSOR_CPP

#include "qtsbetprinter.h"
#include <cmath>
#include <stdio.h>
#include <cstdio>

QtSbetPrinter::QtSbetPrinter(std::string outFilename)
{
    this->outFilename = outFilename;
}

QtSbetPrinter::~QtSbetPrinter(){
}

bool QtSbetPrinter::OpenFile(){
    if(!(file = fopen(outFilename.c_str(), "w"))){
        std::cerr << "Cannot open file " << outFilename << std::endl;
        return false;
    }

    fprintf(file, "Time Latitude Longitude Altitude SpeedX SpeedY SpeedZ Heading Pitch Roll Wander ForceX ForceY ForceZ AngularRateX AngularRateY AngularRateZ\n");

    return true;
}

void QtSbetPrinter::CloseFile(){
    fclose(file);
}


void QtSbetPrinter::processEntry(SbetEntry * entry){

    fprintf(file, "%.12lf %.12lf %.12lf %lf %lf %lf %lf %.12lf %.12lf %.12lf %lf %lf %lf %lf %lf %lf %lf\n",
        entry->time,
        (entry->latitude * 180) / M_PI,
        (entry->longitude* 180) / M_PI,
        entry->altitude,
        entry->xSpeed,
        entry->ySpeed,
        entry->zSpeed,
        entry->heading,
        entry->pitch,
        entry->roll,
        entry->wander,
        entry->xForce,
        entry->yForce,
        entry->zForce,
        entry->xAngularRate,
        entry->yAngularRate,
        entry->zAngularRate
    );
}


#endif
