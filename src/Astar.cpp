//
// Created by lihao on 19-7-9.
//

#include "Astar.h"

<<<<<<< HEAD
namespace astar {

void CAstar::InitAstar(Mat& _Map, AstarConfig _config)
=======
namespace pathplanning{

void Astar::InitAstar(Mat& _Map, AstarConfig _config)
>>>>>>> second commit
{
    Mat Mask;
    InitAstar(_Map, Mask, _config);
}

<<<<<<< HEAD
void CAstar::InitAstar(Mat& _Map, Mat& Mask, AstarConfig _config)
{
    Map = _Map;
    config = _config;
    OpenList.clear();
    PathList.clear();
=======
void Astar::InitAstar(Mat& _Map, Mat& Mask, AstarConfig _config)
{
    char neighbor8[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},            {0, 1},
            {1, -1},   {1, 0},  {1, 1}
    };

    Map = _Map;
    config = _config;
    neighbor = Mat(8, 2, CV_8S, neighbor8).clone();
>>>>>>> second commit

    MapProcess(Mask);
}

<<<<<<< HEAD
void CAstar::PathPlanning(Point _startPoint, Point _targetPoint, vector<Point>& path)
=======
void Astar::PathPlanning(Point _startPoint, Point _targetPoint, vector<Point>& path)
>>>>>>> second commit
{
    // Get variables
    startPoint = _startPoint;
    targetPoint = _targetPoint;

    // Path Planning
    Node* TailNode = FindPath();
    GetPath(TailNode, path);
<<<<<<< HEAD

    // Clear list
    OpenList.clear();
    PathList.clear();
}

void CAstar::DrawPath(Mat& _Map, vector<Point>& path, InputArray Mask, Scalar color,
=======
}

void Astar::DrawPath(Mat& _Map, vector<Point>& path, InputArray Mask, Scalar color,
>>>>>>> second commit
        int thickness, Scalar maskcolor)
{
    if(path.empty())
    {
        cout << "Path is empty!" << endl;
        return;
    }
    _Map.setTo(maskcolor, Mask);
    for(auto it:path)
    {
<<<<<<< HEAD
        rectangle(_Map, it, it, color, thickness);                 // path
    }
}

void CAstar::MapProcess(Mat& Mask)
=======
        rectangle(_Map, it, it, color, thickness);
    }
}

void Astar::MapProcess(Mat& Mask)
>>>>>>> second commit
{
    int width = Map.cols;
    int height = Map.rows;
    Mat _Map = Map.clone();

<<<<<<< HEAD
#if ASTAR_DEBUG
    namedWindow("image", 0);
    imshow("image", _Map);
#endif

=======
>>>>>>> second commit
    // Transform RGB to gray image
    if(_Map.channels() == 3)
    {
        cvtColor(_Map.clone(), _Map, CV_BGR2GRAY);
    }

    // Binarize
    if(config.OccupyThresh < 0)
    {
        threshold(_Map.clone(), _Map, 0, 255, CV_THRESH_OTSU);
    } else
    {
        threshold(_Map.clone(), _Map, config.OccupyThresh, 255, CV_THRESH_BINARY);
    }

<<<<<<< HEAD
#if ASTAR_DEBUG
    namedWindow("Binarize", 0);
    imshow("Binarize", _Map);
#endif

=======
>>>>>>> second commit
    // Inflate
    Mat src = _Map.clone();
    if(config.InflateRadius > 0)
    {
        Mat se = getStructuringElement(MORPH_ELLIPSE, Size(2 * config.InflateRadius, 2 * config.InflateRadius));
        erode(src, _Map, se);
    }

<<<<<<< HEAD
#if ASTAR_DEBUG
    namedWindow("Inflate", 0);
    imshow("Inflate", _Map);
#endif

    // Get mask
    bitwise_xor(src, _Map, Mask);

#if ASTAR_DEBUG
    namedWindow("Mask", 0);
    imshow("Mask", Mask);
#endif

    // Initial LabelMap
    Label = Mat::zeros(height, width, CV_8UC1);
=======
    // Get mask
    bitwise_xor(src, _Map, Mask);

    // Initial LabelMap
    LabelMap = Mat::zeros(height, width, CV_8UC1);
>>>>>>> second commit
    for(int y=0;y<height;y++)
    {
        for(int x=0;x<width;x++)
        {
            if(_Map.at<uchar>(y, x) == 0)
            {
<<<<<<< HEAD
                Label.at<uchar>(y, x) = obstacle;
            }
            else
            {
                Label.at<uchar>(y, x) = free;
=======
                LabelMap.at<uchar>(y, x) = obstacle;
            }
            else
            {
                LabelMap.at<uchar>(y, x) = free;
>>>>>>> second commit
            }
        }
    }
}

<<<<<<< HEAD
Node* CAstar::FindPath()
{
    int width = Map.cols;
    int height = Map.rows;
    Mat _Label = Label.clone();

    // Add startPoint to OpenList
    OpenList.push_back(new Node(startPoint));
    _Label.at<uchar>(startPoint.y, startPoint.x) = inOpenList;
=======
Node* Astar::FindPath()
{
    int width = Map.cols;
    int height = Map.rows;
    Mat _LabelMap = LabelMap.clone();

    // Add startPoint to OpenList
    OpenList.clear();
    OpenList.push_back(new Node(startPoint));
    _LabelMap.at<uchar>(startPoint.y, startPoint.x) = inOpenList;
>>>>>>> second commit

    while(!OpenList.empty())
    {
        // Find the node with least F value
<<<<<<< HEAD
        Node* CurNode = OpenList.front();
        for(auto &it:OpenList)
        {
            if(it->F < CurNode->F)
            {
                CurNode = it;
=======
        Node* CurNode = OpenList[0];
        int index = 0;
        int length = OpenList.size();
        for(int i = 0;i < length;i++)
        {
            if(OpenList[i]->F < CurNode->F)
            {
                CurNode = OpenList[i];
                index = i;
>>>>>>> second commit
            }
        }
        int curX = CurNode->point.x;
        int curY = CurNode->point.y;
<<<<<<< HEAD
        OpenList.remove(CurNode);       // Delete CurNode from OpenList
        _Label.at<uchar>(curY, curX) = inCloseList;
=======
        OpenList.erase(OpenList.begin() + index);       // Delete CurNode from OpenList
        _LabelMap.at<uchar>(curY, curX) = inCloseList;
>>>>>>> second commit

        // Determine whether arrive the target point
        if(curX == targetPoint.x && curY == targetPoint.y)
        {
            return CurNode; // Find a valid path
        }

        // Traversal the neighborhood
<<<<<<< HEAD
        for(int x = curX - 1;x <= curX + 1;x++)
        {
            for(int y = curY - 1;y <= curY + 1;y++)
            {
                if(x < 0 || x >= width || y < 0 || y >= height)
                {
                    continue;
                }
                if(_Label.at<uchar>(y, x) == free || _Label.at<uchar>(y, x) == inOpenList)
                {
                    // Determine whether a diagonal line can pass
                    bool walkable = true;
                    if(x == curX - 1 && _Label.at<uchar>(curY, curX - 1) == obstacle)
                    {
                        walkable = false;
                    }
                    else if(x == curX + 1 && _Label.at<uchar>(curY, curX + 1) == obstacle)
                    {
                        walkable = false;
                    }
                    if(y == curY - 1 && _Label.at<uchar>(curY - 1, curX) == obstacle)
                    {
                        walkable = false;
                    }
                    else if(y == curY + 1 && _Label.at<uchar>(curY + 1, curX) == obstacle)
                    {
                        walkable = false;
                    }
                    if(!walkable)
                    {
                        continue;
                    }

                    // Calculate G, H, F value
                    int addG, G, H, F;
                    if(abs(x - curX) == 1 && abs(y - curY) == 1)
                    {
                        addG = 14;
                    }
                    else
                    {
                        addG = 10;
                    }
                    G = CurNode->G + addG;
                    if(config.Euclidean)
                    {
                        H = round(10 * sqrt((x - targetPoint.x)^2 + (y - targetPoint.y)^2));
                    }
                    else
                    {
                        H = 10 * (abs(x - targetPoint.x) + abs(y - targetPoint.y));
                    }
                    F = G + H;

                    // Update the G, H, F value of node
                    if(_Label.at<uchar>(y, x) == free)
                    {
                        Node* node = new Node();
                        node->point = Point(x, y);
                        node->parent = CurNode;
                        node->G = G;
                        node->H = H;
                        node->F = F;
                        OpenList.push_back(node);
                        _Label.at<uchar>(y, x) = inOpenList;
                    }
                    else // LabelMap.at<uchar>(y, x) == inOpenList
                    {
                        // Find the node
                        Node* node = NULL;
                        for(auto &it:OpenList)
                        {
                            if(it->point.x ==  x && it->point.y ==  y)
                            {
                                node = it;
                            }
                        }
                        if(G < node->G)
                        {
                            node->G = G;
                            node->F = F;
                            node->parent = CurNode;
                        }
=======
        for(int k = 0;k < neighbor.rows;k++)
        {
            int y = curY + neighbor.at<char>(k, 0);
            int x = curX + neighbor.at<char>(k, 1);
            if(x < 0 || x >= width || y < 0 || y >= height)
            {
                continue;
            }
            if(_LabelMap.at<uchar>(y, x) == free || _LabelMap.at<uchar>(y, x) == inOpenList)
            {
                // Determine whether a diagonal line can pass
                bool walkable = true;
                if(y == curY - 1 && _LabelMap.at<uchar>(curY - 1, curX) == obstacle)
                {
                    walkable = false;
                }
                else if(y == curY + 1 && _LabelMap.at<uchar>(curY + 1, curX) == obstacle)
                {
                    walkable = false;
                }

                if(x == curX - 1 && _LabelMap.at<uchar>(curY, curX - 1) == obstacle)
                {
                    walkable = false;
                }
                else if(x == curX + 1 && _LabelMap.at<uchar>(curY, curX + 1) == obstacle)
                {
                    walkable = false;
                }
                if(!walkable)
                {
                    continue;
                }

                // Calculate G, H, F value
                int addG, G, H, F;
                if(abs(x - curX) == 1 && abs(y - curY) == 1)
                {
                    addG = 14;
                }
                else
                {
                    addG = 10;
                }
                G = CurNode->G + addG;
                if(config.Euclidean)
                {
                    int dist2 = (x - targetPoint.x) * (x - targetPoint.x) + (y - targetPoint.y) * (y - targetPoint.y);
                    H = round(10 * sqrt(dist2));
                }
                else
                {
                    H = 10 * (abs(x - targetPoint.x) + abs(y - targetPoint.y));
                }
                F = G + H;

                // Update the G, H, F value of node
                if(_LabelMap.at<uchar>(y, x) == free)
                {
                    Node* node = new Node();
                    node->point = Point(x, y);
                    node->parent = CurNode;
                    node->G = G;
                    node->H = H;
                    node->F = F;
                    OpenList.push_back(node);
                    _LabelMap.at<uchar>(y, x) = inOpenList;
                }
                else // _LabelMap.at<uchar>(y, x) == inOpenList
                {
                    // Find the node
                    Node* node = NULL;
                    int length = OpenList.size();
                    for(int i = 0;i < length;i++)
                    {
                        if(OpenList[i]->point.x ==  x && OpenList[i]->point.y ==  y)
                        {
                            node = OpenList[i];
                            break;
                        }
                    }
                    if(G < node->G)
                    {
                        node->G = G;
                        node->F = F;
                        node->parent = CurNode;
>>>>>>> second commit
                    }
                }
            }
        }
    }

    return NULL; // Can not find a valid path
}

<<<<<<< HEAD
void CAstar::GetPath(Node* TailNode, vector<Point>& path)
{
=======
void Astar::GetPath(Node* TailNode, vector<Point>& path)
{
    PathList.clear();
    path.clear();

>>>>>>> second commit
    // Save path to PathList
    Node* CurNode = TailNode;
    while(CurNode != NULL)
    {
        PathList.push_back(CurNode);
        CurNode = CurNode->parent;
    }

    // Save path to vector<Point>
<<<<<<< HEAD
    path.clear();
    for(auto &it:PathList)
    {
        path.push_back(it->point);
=======
    int length = PathList.size();
    for(int i = 0;i < length;i++)
    {
        path.push_back(PathList.back()->point);
        PathList.pop_back();
>>>>>>> second commit
    }
}

}