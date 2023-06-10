///HERE ^ means dot product of two row vectors and * means scaler multiplication of a vector

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

template <typename T>
class Vector{
private:
    vector<float> arr;
    int len;
public:

    Vector(){
    }

    //taking values from and pushing them in a vector
    Vector(T a[], int length){
        len = length;
        for(int i=0; i< len; i++){
            arr.push_back(a[i]);
        }
    }

    //operator overloading for / division et: vector object / 3
    template <typename Q>
    Vector<T> operator/(Q a) {
        Vector<T> result = *this;
        for (int i = 0; i < len; i++) {
            result.arr[i] = result.arr[i] / a;
        }

        return result;
    }

    //dot product between two vectors returns a scaler value et: vector obj1 ^ vector obj2
    template<typename Q>
    float operator^(const Vector<Q> &v){
        float sum = 0;
        for(int i=0; i<len; i++){
            sum += arr[i] * v.arr[i];
        }

        return sum;
    }

    // subtraction from vector 1 to vector 2 et: vector  obj1 - vector obj2
    template<typename Q>
    Vector<Q> operator-(const Vector<Q> &v){
        Vector<T> v0 = *this;
        for(int i=0; i<len; i++){
            v0.arr[i] = v0.arr[i] - v.arr[i];
        }

        return v0;
    }

    // scaler multiplication of value and a vector et: 3* vector obj
    template <typename Q, typename U>
    friend Vector<U> operator*(Q a, const Vector<U>& v) {
        Vector<U> result = v;
        for (int i = 0; i < result.len; i++) {
            result.arr[i] = result.arr[i] * a;
        }
        return result;
    }



    //returns the magnitude of the vector object
    float mode_value(){
        float sum = 0;
        for(int i=0; i<len; i++){
            sum += (arr[i] * arr[i]);
        }

        return sqrt(sum);
    }

    // display the values of vector (prototype)
    template<typename U>
    friend ostream& operator<<(ostream &out, const Vector<U> &v);


};

//display values of vector (defination)
template <typename T>
ostream& operator<<(ostream &out, const Vector<T> &v){
    for(int i=0; i< v.len; i++){
        out << v.arr[i] << "e" << i;
        if( i != (v.len-1)){
            out << " + ";
        }
    }

    return out;
}



int main()
{
    int n = 4;
    int a[n][n] = {
                    {1, 0, 2, 1},
                    {0, 1, 8, -6},
                    {2, 8, 3, 2},
                    {1, -6, 2, 3}
                };

    Vector<int> v1(a[0], n);
    Vector<int> v2(a[1], n);
    Vector<int> v3(a[2], n);
    Vector<int> v4(a[3], n);
    Vector<int> v[n] = {v1, v2, v3, v4};

    cout << "Initial non orthogonal vectors" << endl;
    cout << "Vector 1: " << v[0] << endl;
    cout << "Vector 2: " << v[1] << endl;
    cout << "Vector 3: " << v[2] << endl;
    cout << "Vector 4: " << v[3] << endl;

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            v[i] = v[i] - ((v[i] ^ v[j]) * v[j]);
        }
        //check if magnitude is close to zero if yes then initialize all values with zero in the vector
        v[i] = v[i] / v[i].mode_value();

    }

    cout << endl << "New orthogonal basis vectors" << endl;
    cout << "Vector 1: " << v[0] << endl;
    cout << "Vector 2: " << v[1] << endl;
    cout << "Vector 3: " << v[2] << endl;
    cout << "Vector 4: " << v[3] << endl;

    return 0;
}



////////Improvments that can be done  adding more overloading operators that behaves like numpy
////////Creating an array for vectors
/////more user interface
////make row vector zero is magnitude is close to zero






//for some reason preivous implementaion using just pointers of array was not working as the values kept
// getting changed as any kind of transformation was done
