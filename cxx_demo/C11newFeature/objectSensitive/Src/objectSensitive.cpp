#include "obj.cpp"

int objectSensitive(){
    //创建对象
    char a[20]="Beijing";

    City Beijing(a);
    City City1("TIANJIN");
    
    Beijing.iPM25=20;
    City1.iPM25=100;
  
    Beijing.reportPM25();
    City1.reportPM25(); 

    City1.cityName = NULL;
    City1.reportPM25();    //not NPD; control flow
    
    City hometown("Hometown");
    hometown.reportPM25(); //UIV; CERT EXP53-CPP. Do not read uninitialized memory

    //delete hometown.cityName;
    free(hometown.cityName);

    hometown.reportPM25(); //UAF:Use After Free; CERT MEM50-CPP. Do not access freed memory

    return 0;
}

int main()
{
    objectSensitive();
}
