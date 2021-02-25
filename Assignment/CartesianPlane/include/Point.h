#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point();
        Point(int, int); //Custom constructor
        virtual ~Point();


    protected:

    private:
        int xCoord; //For retaining x and y component
        int yCoord;

        float distanceFromPoint(Point*); //To calculate distance from another point
        Line determineEquation(Point*); //To determine the equation given another point
        void displayPoint(); //To display the point
};

#endif // POINT_H
