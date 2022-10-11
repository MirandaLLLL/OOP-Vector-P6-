#include<iostream>
#include<string>
#include<windows.h> 

using namespace std;

template<class T>
class Vector {
public:
    Vector();                      // creates an empty vector
    Vector(int size);              // creates a vector for holding 'size' elements
    ~Vector();                     // destructs the vector 
    Vector(const Vector& r) :m_nSize(0), m_nCapacity(0), m_pElements(NULL) {
        *this = r;
    }                              // the copy ctor
    T& operator[](int index);      // accesses the specified element without bounds checking
    T& at(int index);              // accesses the specified element, throws an exception of type 'std::out_of_range' when index < 0 or >= m_nSize
    int size() const;		       // return the size of the container
    void push_back(const T&  x);   // adds an element to the end 
    void clear();                  // clears the contents
    bool empty() const;            // checks whether the container is empty 
private:
    void inflate();                // expand the storage of the container to a new capacity, e.g. 2*m_nCapacity
    T* m_pElements;                // pointer to the dynamically allocated storage
    int m_nSize;                   // the number of elements in the container
    int m_nCapacity;               // the number of elements that can be held in currently allocated storage
};
template<class T> Vector<T>::Vector() {
    m_nSize = 0;                   // create a empty Vector;
    m_nCapacity = 100;             // make the storage of the Vector is 100;
    m_pElements = new T[m_nCapacity]; //require the storage;
}
template <class T>  Vector<T>::~Vector() {
    delete[] m_pElements;          //destruct the Vector;
}
template<class T> Vector<T>::Vector(int size) {
    m_nSize = 0;                   // create a empty Vector;
    m_nCapacity = size;            // make the storage of the Vector is 'size';
    m_pElements = new T[m_nCapacity];  //require the storage;
}

template<class T> int Vector<T>:: size() const {
    return m_nSize;            //output the total sum of the elements in the Vector;
}
template<class T> void Vector<T>::push_back(const T& x) {
    if (m_nSize >= m_nCapacity)   //if m_nSize < m_nCapacity
        inflate();
    //expand the storage;
        m_nSize++;                 //the m_nSize added;
        m_pElements[m_nSize - 1] = x; //add x at the end of the Vector;
}
template<class T> void Vector<T>::clear() {
    m_pElements = NULL;
    m_nSize = 0;                          //empty the m_nSize;
}
template<class T> T& Vector<T>::operator[](int index) {
    return this->m_pElements[index];      //output m_pElements[index];
}
template<class T> T& Vector<T>::at(int index) {
    if (index >= 0 && (index < m_nSize)) {        //when index between 0 and m_nSize;
        return this->m_pElements[index];          //output m_pElements[index];
    }
    else 
        cout << "out_of_range" << endl;          //if not, output "out of range";
}
template<class T> bool Vector<T>::empty()const {
    return m_nSize == 0;                         //if the container is empty, return 1,else return 0;
}
template<class T> void Vector<T>::inflate(){
    m_nCapacity = m_nCapacity * 2;   //double the storage of the container;
    T* temp = m_pElements;           //create a temporary vector to store the original data;
    m_pElements = new T[m_nCapacity];  //allocate twice the space of container
    for (int i = 0; i < m_nSize; i++)   //put the original data into the expanded container;
        m_pElements[i] = temp[i];    
    delete[] temp;                 
}