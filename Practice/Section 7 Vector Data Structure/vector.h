template <typename T>
class Vector
{
    // Data members
    T *arr;
    int cs;
    int ms;

public:
    Vector(int max_size = 1)
    {
        cs = 0;
        ms = max_size;
        arr = new T[ms];
    }

    void push_back(const T data)
    {
        if (cs == ms)
        {
            T *oldArr = arr;
            ms = ms * 2;
            arr = new T[ms];
            for (int i = 0; i < cs; i++)
            {
                arr[i] = oldArr[i];
            }
            delete[] oldArr;
        }

        arr[cs] = data;
        cs++;
    }

    T pop_back()
    {
        T remove = -1;
        if (cs > 0)
        {
            remove = arr[cs - 1];
            cs--;
        }
        return remove;
    }

    bool isEmpty() const
    {
        return cs == 0;
    }

    T front() const
    {
        return arr[0];
    }

    T back()
    {
        return arr[cs - 1];
    }
    T at(int i) const
    {
        return arr[i];
    }

    int size() const
    {
        return cs;
    }

    int capacity() const
    {
        return ms;
    }

    T operator[](const int i) const
    {
        return arr[i];
    }
};