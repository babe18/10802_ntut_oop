#include "../src/polygon.h"

class PolygonTest : public ::testing::Test {
protected:
  void SetUp() {
    double a[] = {0, 0};
  	double b[] = {2, 0};
  	double c[] = {3, 1};
  	double d[] = {2, 2};
  	double e[] = {1, 3};
  	double f[] = {0, 2};
  	u =  new Vector(a, 2);
  	v =  new Vector(b, 2);
  	w =  new Vector(c, 2);
  	x =  new Vector(d, 2);
  	y =  new Vector(e, 2);
  	z =  new Vector(f, 2);
  	Vector arr[]  = {*u, *v, *w, *x, *y, *z};
  	Vector arr0[] = {*x, *z, *u, *y, *v, *w};
  	Vector arr1[] = {*u, *v, *w};				//1	6.57  2+sqrt(2)+sqrt(2)
  	Vector arr2[] = {*u, *v, *w, *x};			//3	7.65  2+4*sqrt(2)
  	Vector arr3[] = {*u, *v, *w, *x, *y};		//5	9.4   2+3*sqrt(2)
  	Vector arr4[] = {*u, *v, *w, *x, *y, *z}; 	//6	9.65  4+4*sqrt(2)
  	p = new Polygon(arr,6);
  	p2 = new Polygon(arr0,6);
  	vec.push_back(new Polygon(arr1, 3));
  	vec.push_back(new Polygon(arr2, 4));
  	vec.push_back(new Polygon(arr3, 5));
  	vec.push_back(new Polygon(arr4, 6));
  }
	Vector *u, *v, *w, *x, *y, *z;
	Polygon *p, *p2;
	std::vector<Polygon *> vec;
};

TEST_F(PolygonTest, defaultConstructor){
    Polygon k;
    ASSERT_EQ(-1, k.sides());
}

TEST_F(PolygonTest,constructorTest){
    ASSERT_EQ(6,p->sides());
    ASSERT_EQ(0,p->point(1).length());
    ASSERT_EQ(2,p->point(2).length());
    ASSERT_EQ(sqrt(10),p->point(3).length());
    ASSERT_EQ(sqrt(8),p->point(4).length());
    ASSERT_EQ(sqrt(10),p->point(5).length());
    ASSERT_EQ(2,p->point(6).length());
}

TEST_F(PolygonTest,pointTest){
    ASSERT_EQ(0,p->point(1).length());
    ASSERT_EQ(2,p->point(2).length());
    ASSERT_EQ(sqrt(10),p->point(3).length());
    ASSERT_EQ(sqrt(8),p->point(4).length());
    ASSERT_EQ(sqrt(10),p->point(5).length());
    ASSERT_EQ(2,p->point(6).length());
}

TEST_F(PolygonTest,sideTest){
    ASSERT_EQ(6,p->sides());
}

TEST_F(PolygonTest, perimeterTest){
	ASSERT_NEAR(4+4*sqrt(2), p2->perimeter(), 0.01);
}

TEST_F(PolygonTest, areaTest){
	ASSERT_NEAR(6, p2->area(), 0.01);
}

TEST_F(PolygonTest, findAllByArea){
	std::vector<Polygon *> result = findAll(vec.begin(), vec.end(), [](Polygon *s) {
		return s->area() > 2 && s->area() < 5.5;
	});
  
	ASSERT_EQ(2, result.size());
	ASSERT_NEAR(3, result[0]->area(), 0.01);
	ASSERT_NEAR(5, result[1]->area(), 0.01);
}

TEST_F(PolygonTest, findAllByPerimeter){
	std::vector<Polygon *> result = findAll(vec.begin(), vec.end(), [](Polygon *s) {
		return s->perimeter() > 7 && s->perimeter() < 9.5;
	});

	ASSERT_EQ(2, result.size());

	ASSERT_NEAR(2+4*sqrt(2), result[0]->perimeter(), 0.01);
	ASSERT_NEAR(2+3*sqrt(2)+sqrt(10), result[1]->perimeter(), 0.01);
}
