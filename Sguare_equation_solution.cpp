#include <stdio.h>
#include <math.h>

void Unitest ();
int Scan_a_b_c(double *a, double *b, double *c);
int Square (double a, double b, double c, double* x1, double* x2, int *N_of_roots);
void Print_root (int Number_of_roots, double x1, double x2);

int main ()
{
    double a=0, b=0, c=0;
    double x1=0, x2=0;
    int Number_of_roots = 0;
    int Need_check = 0;

    printf ("Do you want to check the program? (Yes-press 1, NO-press 2)   ");
    scanf ("%d", &Need_check);

    if (Need_check==1)
        Unitest ();

    if (Scan_a_b_c (&a,&b,&c))
    {
        if (Square (a,b,c,&x1, &x2, &Number_of_roots))
                Print_root (Number_of_roots, x1,x2);
        else
            printf ("NULL\n");
    }
}

int Square (double a, double b, double c, double* x1, double* x2, int *N_of_roots)
{
    if ((x1==NULL)|| (x2==NULL))
        return 0;

    if ((a==0)&&(b==0)&&(c==0))
        {
            *N_of_roots = -1;
            return 1;
        }

    if ((a==0)&&(b==0)&&(c!=0))
        {
            *N_of_roots =  0;
            return 1;
        }

    if ((a==0) && (b!=0))
    {
        *x1=-c/b;
        *N_of_roots =  1;
        return 1;
    }

    double d=b*b-4*a*c;

    if (d<0)
        {
            *N_of_roots =  0;
            return 1;
        }

    if (d==0)
      {
        *x1=-b/2/a;
        *N_of_roots =  1;
        return 1;
      }
    else
        d=sqrt(d);
    *x1=(-b-d)/2/a;
    *x2=(-b+d)/2/a;
    *N_of_roots =  2;
    return 1;
}

void Unitest ()
{
    double x1=0, x2=0;
    int N_of_root;
    int Null_ptr = Square (0,0,0,&x1,&x2, &N_of_root);

    // Test 1: 0 = 0
    if ((N_of_root==-1) &&(Null_ptr))
    {
        printf ("Test 1:\n0x*x+0x+0=0\nNo error\n");
    }
    else
    {
        printf ("Test 1:\n0x*x+0x+0=0\nError\n");
    }

    // Test 2: 1=0
    Null_ptr = Square (0,0,1,&x1,&x2, &N_of_root);
    if ((N_of_root==0) &&(Null_ptr))
    {
        printf ("Test 2:\n0x*x+0x+1=0\nNo error\n");
    }
    else
        printf ("Test 2:\n0x*x+0x+1=0\nError\n");

    // Test 3:x+1=0
    Null_ptr = Square (0,1,1,&x1,&x2, &N_of_root);
    if ((N_of_root==1) && (x1==-1) && (Null_ptr))
    {
        printf ("Test 3:\n0x*x+x+1=0\nNo error\n");
    }
    else
        printf ("Test 3:\n0x*x+x+1=0\nError\n");

    // Test 4: x*x+x+1=0
    Null_ptr = Square (1,1,1,&x1,&x2, &N_of_root);
    if ((N_of_root==0) &&(Null_ptr))
    {
        printf ("Test 4:\nx*x+x+1=0\nNo error\n");
    }
    else
        printf ("Test 4:\nx*x+x+1=0\nError\n");

    // Test 5:x*x+2x-3=0
    Null_ptr = Square (1,2,-3,&x1,&x2, &N_of_root);
    if ((N_of_root==2) && (x1==-3) && (x2==1) && (Null_ptr))
    {
        printf ("Test 5:\nx*x+2x-3=0\nNo error\n\n");
    }
    else
        printf ("Test 5:\nx*x+2x-3=0\nError\n\n");
}

int Scan_a_b_c (double* a, double* b, double* c)
{
    if ((a==NULL) || (b==NULL) || (c==NULL))
        return 0;

    printf ("a = ");
    scanf ("%lg", a);

    printf ("b = ");
    scanf ("%lg", b);

    printf ("c = ");
    scanf ("%lg", c);
    return 1;
}
    void Print_root (int Number_of_roots, double x1, double x2)
{
    switch (Number_of_roots)
    {
    case -1:
    {
        printf ("Root is any real number\n");
        break;
    }
    case 0:
    {
        printf ("No roots\n");
        break;
    }
    case 1:
    {
        printf ("One root: x1 = %lg\n", x1);
        break;
    }
    case 2:
    {
        printf ("Two roots: x1=%lg x2=%lg\n", x1, x2);
        break;
    }
    }
}
