// Sequence.cpp
// Apurva Shah 705595011

#include "Sequence.h"

////////////////////////////////
///  Constructor
////////////////////////////////
Sequence::Sequence()
{
    head = nullptr;
    tail = nullptr;
    m_size = 0;
}

////////////////////////////////
///  Destructor
////////////////////////////////

Sequence::~Sequence()
{
    Node *p;
    p = head;
    while (p != nullptr) // delete every node in the list
    {
        Node *n = p->next;
        delete p;
        p = n;
    }
}

////////////////////////////////
///  Copy Const
////////////////////////////////
Sequence::Sequence(const Sequence &src)
{
    if (src.head == nullptr) // if empty list
    {
        head = nullptr;
        tail = nullptr;
        m_size = 0;
    }
    else
    {
        head = nullptr; // make sure we make it an empty list
        tail = nullptr;
        m_size = 0;
        ItemType p;
        for (int i = 0; i < src.m_size; i++) // add items to the list
        {
            src.get(i, p);
            addRear(p);
        }
        m_size = src.m_size;
    }
    // return someSeq;
}

////////////////////////////////
///  Assignment Opp
////////////////////////////////
Sequence &Sequence::operator=(const Sequence &src)
{
    if (this != &src)
    {
        Sequence temp(src);
        swap(temp);
    }
    return *this;
}

int Sequence::size() const
{
    return m_size;
}

bool Sequence::empty() const
{
    return (m_size == 0);
}

/////////////////////////////////////
///  Inseration / Member Functions
////////////////////////////////////
int Sequence::insert(int pos, const ItemType &value)
{
    // bad arguments
    if (pos < 0 || pos > size())
    {
        return -1;
    }

    // adding front
    else if (pos == 0)
        addFront(value);

    // adding to th eback
    else if (pos == size())
    {
        addRear(value);
    }

    else
    {
        add_to_sequence(pos, value);
    }

    return pos;
}

////////////////////////////////
///  Inseration / Member Functions
////////////////////////////////

int Sequence::insert(const ItemType &value)
{
    // adding to the front
    if (head == nullptr)
        addFront(value);

    // checking to make sure that is less and then adds to the front of first element
    else if (head->value >= value)
    {
        addFront(value);
        return 0;
    }

    // adding to the rest of the linekd list
    else
    {
        Node *p;
        int pos_counter = 1;
        for (p = head; p != nullptr && p->next != nullptr && value > p->next->value; p = p->next)
            pos_counter++;
        add_to_sequence(pos_counter, value);
        return pos_counter;
    }
    return 0;
}

////////////////////////////////
///  Erasing the pos
////////////////////////////////
bool Sequence::erase(int pos)
{
    // checls if correct pos
    if (pos < 0 || pos >= size())
        return false;
    // verifies lullptr
    if (head == nullptr)
        return false;
    // else returns this
    return (delete_element(pos));
}

////////////////////////////////
///  removal
////////////////////////////////
int Sequence::remove(const ItemType &value)
{ // removes all variables that are in sequence defined
    if (head == nullptr)
        return 0;

    Node *p = head;
    int pos_pos_counter = 0;
    int pos = 0;
    while (p != nullptr)
    {
        if (p->value == value)
        {
            p = p->next;
            erase(pos);
            pos_pos_counter++;
            pos--;
        }
        else
            p = p->next;
        pos++;
    }
    return pos_pos_counter;
}

bool Sequence::get(int pos, ItemType &value) const
{ // get value from pos adn store into item type
    // check for invalid
    if (pos < 0 || pos >= size())
        return false;

    // check for empty
    if (head == nullptr)
        return false;

    Node *m;
    int pos_pos_counter = 0;
    for (m = head; m != nullptr; m = m->next) // locate the position and get p to point at it
    {
        if (pos_pos_counter == pos)
        {
            value = m->value; // copy the value
            return true;
        }
        pos_pos_counter++;
    }

    return false;
}

////////////////////////////////
///  set item form value
////////////////////////////////
bool Sequence::set(int pos, const ItemType &value)
{
    // check for invalid
    if (pos < 0 || pos >= size())
        return false;

    // checks for empty set (memory leak causer)
    if (head == nullptr)
        return false;

    Node *m;
    int pos_pos_counter = 0;
    for (m = head; m != nullptr; m = m->next) // locate the position and get p to point at it
    {
        if (pos_pos_counter == pos)
            break;
        pos_pos_counter++;
    }
    m->value = value; // copy the value
    return true;
}

////////////////////////////////
///  find item in the seq
////////////////////////////////
int Sequence::find(const ItemType &value) const
{
    Node *p;
    int pos_counter = 0;
    for (p = head; p != nullptr; p = p->next)
    {
        if (p->value == value)
            return pos_counter;
        pos_counter++;
    }
    return -1;
}

////////////////////////////////
///  swap
////////////////////////////////
void Sequence::swap(Sequence &other)
{
    // copy over the private variables
    int tempSize = m_size;
    m_size = other.m_size;
    other.m_size = tempSize;
    // copy over the sequences
    // stores the pointers into something else
    Node *p = head;
    Node *m = tail;

    //
    head = other.head;
    tail = other.tail;

    other.head = p;
    other.tail = m;
}

////////////////////////////////
///  main private to add items
////////////////////////////////

void Sequence::addFront(const ItemType &value)
{
    Node *p;
    p = new Node;
    p->value = value;

    // empty
    if (head == nullptr)
    {
        // fill node
        p->next = head;
        p->prev = nullptr;
        head = p;
        tail = p;
    }
    else
    {
        p->next = head;
        p->prev = nullptr;
        p->next->prev = p;
        head = p;
    }

    m_size++;
}

void Sequence::addRear(const ItemType &value)
{
    // checks if the sequence is empty
    if (head == nullptr || tail == nullptr)
        addFront(value);
    else
    {
        // fill in node
        Node *n;
        n = new Node;
        n->value = value;
        // alter linking
        n->next = nullptr;
        n->prev = tail;
        tail->next = n;
        tail = n;

        m_size++;
    }
}

void Sequence::add_to_sequence(int pos, const ItemType &value)
{

    // gets to the right element
    int pos_counter = 0;
    Node *p = head;
    while (p != nullptr)
    {
        if (pos_counter == pos - 1)
            break;
        pos_counter++;
        p = p->next;
    }

    // checks if is last element
    if (p->next == nullptr)
        addRear(value);
    else
    {
        Node *new_node = new Node;
        new_node->value = value;
        new_node->next = p->next;
        if (new_node->next->prev != nullptr)
            new_node->next->prev = new_node;
        new_node->prev = p;
        p->next = new_node;
        m_size++;
    }
}


////////////////////////////////
///  removing items
////////////////////////////////
bool Sequence::delete_element(int pos)
{
    // front of the thing so need to alter head and stuff
    if (pos == 0)
    {
        if (m_size > 1)
        {
            Node *to_be_deleted = head;
            head = to_be_deleted->next;
            to_be_deleted->next->prev = nullptr;
            delete to_be_deleted; // free space
            m_size--;
            return true;
        }
        else
        {
            Node *to_be_deleted = head;
            head = to_be_deleted->next;
            to_be_deleted->prev = nullptr;
            delete to_be_deleted;    // free space
            m_size--;
            return true;
        }
    }

    // anywhere else
    else
    {
        int pos_counter = 0;
        Node *p = head;
        while (p != nullptr)
        {
            if (pos_counter == pos - 1)
                break;
            pos_counter++;
            p = p->next;
        }
        if (p->next->next != nullptr)
        {
            Node *to_be_deleted = p->next;
            p->next = to_be_deleted->next;
            to_be_deleted->next->prev = to_be_deleted->prev;
            delete to_be_deleted;
            m_size--;
            return true;
        }
        // last element in the entire list
        else if (p->next->next == nullptr)
        {
            Node *to_be_deleted = p->next;
            p->next = nullptr;
            tail = p;
            delete to_be_deleted;
            m_size--;
            return true;
        }
    }
    return false;
}

////////////////////////////////
///  subsequence function
////////////////////////////////

int subsequence(const Sequence &seq1, const Sequence &seq2)
{
    ItemType value1;
    ItemType head2;
    ItemType value2;

    // sets initial defualt return
    int m_return = -1;

    seq2.get(0, head2);
    for (int i = 0; i < seq1.size(); i++)
    { // will loop through entire seq
        seq1.get(i, value1); // gets the value

        if (value1 == head2)
        { // now if the value is in it, start another for loop to compare the values
            int pos_counter = 0;
            for (int j = 0; j < seq2.size(); j++)
            {
                seq1.get((i + j), value1);
                seq2.get(j, value2);
                if (value1 == value2)
                { // compare the values for the subseq
                    pos_counter++;
                }

                if (pos_counter == seq2.size())
                {
                    m_return = i; // correct implementation
                }
            }
        }
    }
    return m_return;
}

////////////////////////////////
///  INTERLEAVE
////////////////////////////////

void interleave(const Sequence &seq1, const Sequence &seq2, Sequence &result)
{
    // alias protection smallberg talked about
    Sequence temp;

    // ensuring the copying of seq1 into seq2
    if (seq1.empty() && !(seq2.empty()))
    {
        for (int i = 0; i < seq2.size(); i++)
        {
            ItemType p; // use get and insert!
            seq2.get(i, p);
            temp.insert(i, p);
        }
    }

    // checking if seq 2 empty so we can copy seq 1 into it
    else if (seq2.empty() && !(seq1.empty()))
    {
        for (int i = 0; i < seq1.size(); i++)
        {
            ItemType p;
            seq1.get(i, p);
            temp.insert(i, p);
        }
    }

        // check which one is bigger
    else if (!seq1.empty() && !seq2.empty())
    {
        if (seq1.size() == seq2.size())
        {
            int pos_counter = 0;
            for (int i = 0; i < seq1.size(); i++)
            {
                ItemType far;
                ItemType car;
                seq1.get(i, far);
                seq2.get(i, car);
                temp.insert(pos_counter, far);
                pos_counter++;
                temp.insert(pos_counter, car);
                pos_counter++;
            }
        }
        // 1 is bigger than 2
        else if (seq1.size() < seq2.size())
        {
            int real_pos = 0;
            int pos_counter = 0;
            // start for loop
            for (int i = 0; i < seq1.size(); i++)
            {
                ItemType far;
                seq1.get(i, far); // get the value into this temp
                temp.insert(real_pos, far);
                real_pos++;
                ItemType car;
                seq2.get(i, car);
                temp.insert(real_pos, car);
                real_pos++;
                pos_counter++;
            }
            for (int j = pos_counter; j < seq2.size(); j++)
            {
                ItemType far;
                seq2.get(j, far);
                temp.insert(real_pos, far);
                real_pos++;
            }
        }

        else if (seq2.size() < seq1.size())
        {
            int real_pos = 0;
            int pos_counter = 0;
            for (int i = 0; i < seq2.size(); i++)
            {
                ItemType far;
                seq1.get(i, far);
                temp.insert(real_pos, far);
                real_pos++;
                ItemType car;
                seq2.get(i, car);
                temp.insert(real_pos, car);
                real_pos++;
                pos_counter++;
            }
            for (int j = pos_counter; j < seq1.size(); j++)
            {
                ItemType far;
                seq1.get(j, far);
                temp.insert(real_pos, far);
                real_pos++;
            }
        }
    }
    result.swap(temp); // swap temp with result
}
