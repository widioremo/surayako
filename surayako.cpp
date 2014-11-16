
/*

WIDI OCHIENG OREMO 
cs282-2101/2013

BSc Computer Technology
Project for Multimedia Applicatins
Year 2, Sem 1, november 2014

Date: 16/11/2014


I used Open Computer Vision Library (OpenCV) on my project.

References:
1.Leaning OpenCV by Gary Bradski and Adrian Kaehler - O'Reilly 
        
2.http://www.cs.princeton.edu/courses/archive/fall08/cos429/CourseMaterials/Precept1/facedetect.pdf

3. Face and Eye Detection Using OpenCV: Step by Step 
        by Mahdi Rezaei
        Department of Computer Science, the University of Auckland


   ,-,--.                            ,---.                            ,---.      ,--.-.,-.   _,.---._     
 ,-.'-  _\ .--.-. .-.-. .-.,.---.  .--.'  \            ,--.-.  .-,--.--.'  \    /==/- |\  \,-.' , -  `.   
/==/_ ,_.'/==/ -|/=/  |/==/  `   \ \==\-/\ \          /==/- / /=/_ /\==\-/\ \   |==|_ `/_ /==/_,  ,  - \  
\==\  \   |==| ,||=| -|==|-, .=., |/==/-|_\ |         \==\, \/=/. / /==/-|_\ |  |==| ,   /==|   .=.     | 
 \==\ -\  |==|- | =/  |==|   '='  /\==\,   - \         \==\  \/ -/  \==\,   - \ |==|-  .||==|_ : ;=:  - | 
 _\==\ ,\ |==|,  \/ - |==|- ,   .' /==/ -   ,|          |==|  ,_/   /==/ -   ,| |==| _ , \==| , '='     | 
/==/\/ _ ||==|-   ,   /==|_  . ,'./==/-  /\ - \         \==\-, /   /==/-  /\ - \/==/  '\  \==\ -    ,_ /  
\==\ - , //==/ , _  .'/==/  /\ ,  )==\ _.\=\.-'         /==/._/    \==\ _.\=\.-'\==\ /\=\.''.='. -   .'   
 `--`---' `--`..---'  `--`-`--`--' `--`                 `--`-`      `--`         `--`        `--`--''     


*///////////////////////////////////////////////////////


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace cv;
using namespace std;

//Includes the xml cascade file used to identify features in face recognition
const char* cascade_name = "SuraYako\\MyCascade\\haarcascade_frontalface_alt.xml";//This is the directory with my cascade file, you can edit it to suit you.

int main ( int argc  /*, const char* argv[]*/ )


{

//void detectFaces();


CvHaarClassifierCascade *cascade = (CvHaarClassifierCascade*)cvLoad( cascade_name);

//creates window named sura yako
cvNamedWindow( "Sura Yako ! ",0);

//creates a buffer to store the loaded image
CvMemStorage *storage;

storage = cvCreateMemStorage(0);

//pointer to store loaded image,  IplImage is

IplImage *inImage = cvLoadImage("SuraYako\\MyImages\\15.jpg",1); //This is the directory where it loads the image from. you can change it

//checks that the pointers are not empty, incase of any null pointers it produces an error message.
if( !cascade || !storage || !inImage)
{
printf("Initialization Failed:%s\n",
(!cascade)? " Cascade file not found !\n":
(!storage)? " Not memmory allocated or not enough memory !\n":
" The input file can not be found!\n");
system("pause");
return 0;
}

/*cvHaarDetectObject does the actual face recognition.
it accepts the image, the cascade file and storage location
cvSize determines the size of the smallest face to be looked for

1.4 -> scale rate specifies how quickly opencv should increase the
scale for face detections

faces - counts the detected faces, the for loop draws a
rectangle for each of the detected faces
*/


CvSeq * faces = cvHaarDetectObjects( inImage, cascade, storage,
1.4, 1, 0, cvSize( 10, 10 ) );

for( int i = 0 ; i < ( faces ? faces->total : 0 ) ; i++ )
{
CvRect* r = ( CvRect* )cvGetSeqElem( faces, i );
cvRectangle( inImage,
cvPoint( r->x, r->y ),
cvPoint( r->x + r->width, r->y + r->height ),
CV_RGB( 0, 255, 0 ), 2, 8, 0 );
}




////releasing the used memory

cvReleaseHaarClassifierCascade(&cascade);
cvReleaseMemStorage(&storage);

//cvReleaseImage( &inImage );

cvShowImage( "Sura Yako !", inImage );
cvWaitKey(0);
cvReleaseImage( &inImage );
cvDestroyWindow("Sura Yako !");
return 0;

}

/*
void detectFaces()
{

CvSeq * faces = cvHaarDetectObjects( newframe, cascade, storage,
1.4, 1, 0, cvSize( 100, 100 ) );

for( int i = 0 ; i < ( faces ? faces->total : 0 ) ; i++ )
{
CvRect* r = ( CvRect* )cvGetSeqElem( faces, i );
cvRectangle( newframe,
cvPoint( r->x, r->y ),
cvPoint( r->x + r->width, r->y + r->height ),
CV_RGB( 0, 255, 0 ), 2, 8, 0 );
}


}
*/
