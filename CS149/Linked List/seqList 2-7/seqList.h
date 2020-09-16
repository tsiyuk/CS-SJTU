#ifndef SEQLIST_H
#define SEQLIST_H


template<class elemType>
class seqList
{
    friend seqList<elemType> operator+(const seqList<elemType> &s1,const seqList<elemType> &s2);

    public:
        seqList(int iniSize=10);
        ~seqList();
        seqList(const seqList<elemType> &obj);
        void clear();
        int length()const;
        void insert(int i,const elemType &x);
        void remove(int i);
        seqList<elemType>& operator=(const seqList<elemType> &right);

    private:
        elemType *data;
        int currentLength;
        int maxSize;
        void doubleSpace();
};

#endif // SEQLIST_H
