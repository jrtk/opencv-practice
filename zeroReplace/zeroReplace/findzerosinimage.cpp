#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>

/*
Find all pixels with value 0. Assign the value of 255 to those pixels. 

*/

// g++ -o img img.cpp `pkg-config --cflags --libs opencv`
using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    if( argc != 2)
    {
     cout <<" Usage: display_image ImageToLoadAndDisplay" << endl;
     return -1;
    }

    Mat image, destimg;
   // Let me load the image file.
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);   // Read the file
  // Convert into Gray Scale. 
    cvtColor (image, destimg, COLOR_BGR2GRAY);

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

   // OpenCV API that already counts nonZero Values in the given Image.
    int x = countNonZero(destimg);
    cout <<"count-nonZero " << x<<endl;
    cout <<"Acrual Images row "<<destimg.rows << " cols "<<destimg.cols <<" Size " <<destimg.rows *destimg.cols <<endl;

   int zeroCount=0;

     
  unsigned char val;
  for ( int i=0; i< destimg.rows; i++) {
	  for (int j=0; j<destimg.cols; j++) {
		  val =destimg.at<uchar>(i,j);
		  if ( val  == 0 )
		  {
			  zeroCount++; 
			  destimg.at<uchar>(i,j) = 255;
		  }
	  }	
  }


    cout <<"Zero Count is " << zeroCount<<endl;

    namedWindow( "Display window", WINDOW_AUTOSIZE );
    imshow( "original image", image );                   
    imshow( "modified image", destimg );                   

    waitKey(0);                                          
    return 0;
}
