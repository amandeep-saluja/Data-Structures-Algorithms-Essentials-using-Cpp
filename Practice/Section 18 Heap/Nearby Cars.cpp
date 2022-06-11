#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Car
{
public:
    string id;
    int x, y;
    Car(string id, int x, int y)
    {
        this->id = id;
        this->x = x;
        this->y = y;
    }

    int dist() const
    {
        return this->x * this->x + this->y * this->y;
    }
};
class Comparator
{
public:
    bool operator()(const Car c1, const Car c2)
    {
        return c1.dist() < c2.dist();
    }
};

bool compare(const Car c1, const Car c2)
{
    return c1.dist() < c2.dist();
}

void printNearestCars(vector<Car> cars, int k)
{
    priority_queue<Car, vector<Car>, Comparator> max_heap(cars.begin(), cars.begin() + k);
    int i = k;

    while (i < cars.size())
    {
        auto car = cars[i];
        if (car.dist() < max_heap.top().dist())
        {
            max_heap.pop();
            max_heap.push(cars[i]);
        }
        i++;
    }

    vector<Car> output;
    while (!max_heap.empty())
    {
        output.push_back(max_heap.top());
        max_heap.pop();
    }
    sort(output.begin(), output.end(), compare);
    for (Car c : output)
    {
        cout << c.id << endl;
    }
}

int main()
{

    int N, K;
    cin >> N >> K;

    string id;
    int x, y;

    vector<Car> cars;

    for (int i = 0; i < N; i++)
    {
        cin >> id >> x >> y;
        Car car(id, x, y);
        cars.push_back(car);
    }

    printNearestCars(cars, K);

    return 0;
}