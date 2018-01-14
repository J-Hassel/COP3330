class Triangle
{
public:
   Triangle();							//Initializes sideLength to 1;
   Triangle(int l, char b = '#', char f = '*');			//Allows user to initialize sideLength

   //accessors
   int GetSize() const;
   int Perimeter() const;
   double Area() const;
   void Draw() const;
   void Summary() const;

   //mutators
   void Grow();
   void Shrink();
   void SetBorder(char b);
   void SetFill(char f);

private:
   int sideLength;
   char border;
   char fill;
};
