//
// Created by lihao on 19-7-9.
//

<<<<<<< HEAD
#ifndef ASTAR_ASTAR_H
#define ASTAR_ASTAR_H
=======
#ifndef ASTAR_H
#define ASTAR_H
>>>>>>> second commit

#include <iostream>
#include <opencv2/opencv.hpp>

<<<<<<< HEAD

#define ASTAR_DEBUG false

=======
>>>>>>> second commit
using namespace std;
using namespace cv;


<<<<<<< HEAD
namespace astar{
=======
namespace pathplanning{
>>>>>>> second commit

enum NodeType{
    obstacle = 0,
    free,
    inOpenList,
    inCloseList
};

struct Node{
    Point point;  // node coordinate
    int F, G, H;  // cost
    Node* parent; // parent node

    Node(Point _point = Point(0, 0)):point(_point), F(0), G(0), H(0), parent(NULL)
    {
    }
};

struct AstarConfig{
    bool Euclidean;         // true/false
<<<<<<< HEAD
    int OccupyThresh;    // 0~255
    int InflateRadius;      // integer

    AstarConfig(bool _Euclidean = false, int _OccupyThresh = -1, int _InflateRadius = -1):
=======
    int OccupyThresh;       // 0~255
    int InflateRadius;      // integer

    AstarConfig(bool _Euclidean = true, int _OccupyThresh = -1, int _InflateRadius = -1):
>>>>>>> second commit
        Euclidean(_Euclidean), OccupyThresh(_OccupyThresh), InflateRadius(_InflateRadius)
    {
    }
};

<<<<<<< HEAD
class CAstar{
=======
class Astar{
>>>>>>> second commit

public:
    // Interface function
    void InitAstar(Mat& _Map, AstarConfig _config = AstarConfig());
    void InitAstar(Mat& _Map, Mat& Mask, AstarConfig _config = AstarConfig());
    void PathPlanning(Point _startPoint, Point _targetPoint, vector<Point>& path);
    void DrawPath(Mat& _Map, vector<Point>& path, InputArray Mask = noArray(), Scalar color = Scalar(0, 0, 255),
            int thickness = 1, Scalar maskcolor = Scalar(255, 255, 255));

private:
    void MapProcess(Mat& Mask);
    Node* FindPath();
    void GetPath(Node* TailNode, vector<Point>& path);

private:
    //Object
    Mat Map;
    Point startPoint, targetPoint;
<<<<<<< HEAD

    Mat Label;
    AstarConfig config;
    list<Node*> OpenList;  // open list
    list<Node*> PathList;  // path list
=======
    Mat neighbor;

    Mat LabelMap;
    AstarConfig config;
    vector<Node*> OpenList;  // open list
    vector<Node*> PathList;  // path list
>>>>>>> second commit
};

}




<<<<<<< HEAD
#endif //ASTAR_ASTAR_H
=======
#endif //ASTAR_H
>>>>>>> second commit
