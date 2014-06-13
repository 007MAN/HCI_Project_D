#pragma once

#include "ofMain.h"
#include "ofxTuioClient.h"
// for openGL
#include "ofGLRenderer.h"
#include <array>
//#include "mydata.h"

#define WINDOW_WIDTH 1680
#define WINDOW_HEIGHT 1050

// #define WINDOW_WIDTH 1024
// #define WINDOW_HEIGHT 768
#define MAX_NUM 20

using namespace std;
//���� ���
enum myMode
{
	M_OUT,
	M_TAP,
	M_DOUBLETAP,
	M_DRAG,
	M_SCALE,
	M_ROTATE,
	M_NAVIGATION,
	M_MOVE,
	M_ZOOM
};

//�� �̹���
struct myImage{
	ofImage m_Image;
	bool m_isCover;
	float m_ImgPositionX;
	float m_ImgPositionY;
	float m_ImgWidth;
	float m_ImgHeight;
	float m_ImgRotateAngle;
	float m_Distance;
	bool m_isVisible;
	myMode m_Mode;
	myImage* nextImage;
};


class ImageExample : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

	// added to Example
		ofxTuioClient MyClient;

		void touchDown(ofTouchEventArgs & touch);
		void touchMoved(ofTouchEventArgs & touch);
		void touchUp(ofTouchEventArgs & touch);

		//Ŀ���� �̺�Ʈ
		void out(ofTouchEventArgs & touch);
		void tap(ofTouchEventArgs & touch);
		void doubleTap(ofTouchEventArgs & touch);
		void drag(ofTouchEventArgs & touch);
		void scale(TUIO::TuioCursor* cursor1 ,TUIO::TuioCursor* cursor2);
		void rotate(TUIO::TuioCursor* cursor1 ,TUIO::TuioCursor* cursor2);
		void navigate(float positionX, float positionY);
		void move(ofTouchEventArgs & touch);

		myImage* getCurrentImage(TUIO::TuioCursor* cursor);
		void showImages(myImage* album);
		void hideImages(myImage* album);
		void moveAlbum(ofTouchEventArgs & touch,myImage* album);
		void moveImage(ofTouchEventArgs & touch, myImage* image);
		myImage* getZoomingImage(TUIO::TuioCursor* cursor1,TUIO::TuioCursor* cursor2,TUIO::TuioCursor* cursor3);
		void zoomAlbum(myImage* album, TUIO::TuioCursor* cursor1);


private:
	ofGLRenderer m_OpenGLRenderer;
	//�ٹ�
	array<myImage*,MAX_NUM> m_Album;
	//Ÿ�� ����
	unsigned long long m_elapsedTime;
	//��ü���� ���
	myMode m_Mode;
	//���� ���õ� �̹���(�ϴ� �Ѱ��� �⺻�����Ѵ�)
	myImage* m_currentElement;
	float m_backOriginX;
	float m_backOriginY;
	float m_currentAngle;
	float m_distance;

	ofImage m_backImage;
};
