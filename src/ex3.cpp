#include <iostream>

class Beam
{
private:
    // double _l1, _l2, _iy1, _iy2, _q1, _q2, _x;

public:
    // Beam(double l1, double l2, double iy1, double iy2, double q1, double q2, double x)
    double l1, l2, iy1, iy2, x;

    float computeMoment(float q1, float q2, float samples, float itr )
    {
        calcX(samples, itr);

        if (x <= l1)
        {
            float a = calc_Mb(q1, q2);
            float b = (x / l1);
            float c = ( (q1 * l1 * l1) / 2 );
            float d = calc_w1();
            return a*b-c*d;
        }
        else
        {
            float a = calc_Mb(q1, q2);
            float b = (1 - ( (x - l1) / l2 ));
            float c =  ( (q2 * l2 * l2) / 2);
            float d = calc_w2();
            return a*b-c*d;
        }
    }

    float calc_Mb(float q1, float q2)
    {
        float num = ( (q1 * std::pow(l1, 3)) + (q2 * std::pow(l2, 3) * calc_j())  );
        float den = ( 8 * (l1 + (l2 * calc_j())) );
        return num / den;
    }
    float calc_j()
    {
        return iy1 / iy2;
    }
    float calc_w1()
    {
        return (x / l1) - std::pow( ( x / l1 ), 2);
    }
    float calc_w2()
    {
        float a = ( (x - l1) / l2 );
        float b = std::pow( ( (x - l1) / l2 ), 2);
        return a - b;
    }
    void calcX (float samples, float itr)
    {
        x = itr * ((l1 + l2) / samples) ;
        std::cout << "x: "<< x << " ----------  M(x) [kNm] = ";
    }


    // Getter functions

    // Setter functions
    void set_beam_length(float length) 
    {
        this->l1 = length;
    }


};


int main()
{
    Beam b;
    Beam* bm = &b;
    float q1 = 20;
    float q2 = 40;
    float samples = 10;
    // b.Mb()

    // b.set_beam_length(5)

    bm->l1 = 4;
    bm->l2 = 6;
    bm->iy1 = 0.0000425;
    bm->iy2 = 0.0000425;

    std::cout << "Input values: "
              << std::endl;
    
    std::cout << "Load q1 [kN/m] = " << q1 << std::endl;
    std::cout << "Load q2 [kN/m] = " << q2 << std::endl;
    std::cout << "Samples (points) = " << samples << std::endl;
    std::cout << "Length 1 [m] = " << bm->l1 << std::endl;
    std::cout << "Length 2 [m] = " << bm->l2 << std::endl;
    std::cout << "Moment of inertia 1 [m^4] = " << bm->iy1 << std::endl;
    std::cout << "Moment of inertia 2 [m^4] = " << bm->iy2 << std::endl;

    std::cout<< std::endl;
    std::cout<< std::endl;
    std::cout << "Output:" << std::endl;
    for (int i = 0; i < samples; i++)
    {
        float itr = i+1;
        std::cout << b.computeMoment(q1, q2, samples, itr) << std::endl;
    }

}