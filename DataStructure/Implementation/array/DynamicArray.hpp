//实现一个动态扩容的数组
class DynamicArray{
    public:
    DynamicArray():m_capacity(8), m_size(0), m_data(new int[m_capacity]){}

    ~DynamicArray(){
        delete[] m_data;
    }

    void push_back(int value){
        if(m_size==m_capacity){
            int new_capacity = m_capacity * 2;
            int* new_data = new int[new_capacity];
            for(int i = 0; i<m_capacity;i++){
                new_data[i] = m_data[i];
            }
            delete[] m_data;
            m_data = new_data;
            m_capacity = new_capacity;
        }
        m_data[m_size++]=value;
    }

    int operator[](int index){
        return m_data[index];
    }

    int size() const {
        return m_size;
    }

    private:
    int m_capacity;
    int m_size;
    int* m_data;
}