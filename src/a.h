class MySample{
public:
    MySample();
    void initD(){
        d=1;
    }
    void initSample();
    void print();
private:
    int a;
    int b;
    int c;
    int d;
    int e;

    struct Sample_s{
        int s_a;
        int s_b;
        int s_c[8];
        int s_d[8];
        Sample_s(){
            s_a=1;
//    s_b=1;
            for (int i=0;i<8;i++)
                s_c[i]=0;
//    s_d = {0,1,2,3,4,5,6,7}
        }
    };
};
