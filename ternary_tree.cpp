#include "ternary_tree.h"
#include <vector>
#include <sstream>

TernaryTree::TernaryTree(){
    root=cursor=nullptr;
}

TernaryTree::TernaryTree(const TernaryTree& _other){
    this->root= _copyOf(_other.root, nullptr);
    this->cursor=this->root; //vagy =_other.cursor;
}

TernaryTree &TernaryTree::operator=(const TernaryTree& _other){
    if(&_other==this) return *this;
    _destroy(this->root);
    this->root= _copyOf(_other.root, nullptr);
    this->cursor=this->root; //vagy =_other.cursor;
    return *this;
}

TernaryTree::~TernaryTree() {
    _destroy(root);
}

/*
 * Balra tömörítve hozzáad a fához egy értéket.
 */
void TernaryTree::addValue(long val){
    auto* n=new TernaryNode(val, nullptr);
    if(root==nullptr){ root=cursor=n; return; }

    std::vector<TernaryNode*>prevV;
    std::vector<TernaryNode*>nextV;
    prevV.push_back(root);

    while(true){
        for(auto & i : prevV){
            if(i->left==nullptr){
                i->left=n;
                n->parent=i;
                return;
            }else nextV.push_back(i->left);

            if(i->middle==nullptr){
                i->middle=n;
                n->parent=i;
                return;
            }else nextV.push_back(i->middle);

            if(i->right==nullptr){
                i->right=n;
                n->parent=i;
                return;
            }else nextV.push_back(i->right);
        }
        prevV=nextV;
        nextV.clear();
    }
}

/*
 * Óra járásával ellentétes irányba forgatja a fát.
 * NoRightChildException-t dob, ha nincs jobb gyerek, amit
 * "felforgatna" a metódus.
 */
void TernaryTree::rotateAnticlockwise() noexcept(false) {
    if(cursor==nullptr) throw NoRightChildException();

    TernaryNode* x=cursor->right;
    if(cursor->right==nullptr) throw NoRightChildException();

    cursor->right=x->left;
    if(x->left!=nullptr) x->left->parent=cursor;

    x->parent=cursor->parent;
    if(cursor->parent==nullptr) root=x;
    else if(cursor==cursor->parent->left) cursor->parent->left=x;
    else cursor->parent->right=x;

    x->left=cursor;
    cursor->parent=x;

    //Ha azt akarjuk, hogy a cursor ne ugyan arra a szamra, hanem ugyan arra a poziciora mutasson akkor...
    cursor=cursor->parent;
}

/*
 * Óra járásával megegyező irányba forgatja a fát.
 * NoLeftChildException-t dob, ha nincs bal gyerek, amit
 * "felforgatna" a metódus
 */
void TernaryTree::rotateClockwise() noexcept(false) {
    if(cursor==nullptr) throw NoLeftChildException();

    TernaryNode* x=cursor->left;
    if(cursor->left==nullptr) throw NoLeftChildException();

    cursor->left=x->right;
    if(x->right!=nullptr) x->right->parent=cursor;

    x->parent=cursor->parent;
    if(cursor->parent==nullptr) root=x;
    else if(cursor==cursor->parent->left) cursor->parent->left=x;
    else cursor->parent->right=x;

    x->right=cursor;
    cursor->parent=x;

    //Ha azt akarjuk, hogy a cursor ne ugyan arra a szamra, hanem ugyan arra a poziciora mutasson akkor...
    cursor=cursor->parent;
}

/*
 * A moveCursor metódus a kurzort a kívánt irányba mozgatja.
 * Ha az adott irányba nem mozgatható a kurzor, akkor a vonatkozó
 * kivételt dobja (NoLeftChildException, NoRightChildException,
 * NoMiddleChildException, NoParentException).
 */
void TernaryTree::moveCursor(CursorDirection dir) noexcept(false){
    if(dir==top){
        cursor=root;
    }
    else if(dir==up){
        if(cursor->parent==nullptr) throw NoParentException();
        else cursor=cursor->parent;
    }
    else if(dir==left){
        if(cursor->left==nullptr) throw NoLeftChildException();
        else cursor=cursor->left;
    }
    else if(dir==middle){
        if(cursor->middle==nullptr) throw NoMiddleChildException();
        else cursor=cursor->middle;
    }
    else if(dir==right){
        if(cursor->right==nullptr) throw NoRightChildException();
        else cursor=cursor->right;
    }
}

/*
 * Ez a metódus elvégzi a hármas fán a Knuth-transzformációt.
 */
BinaryTree* TernaryTree::generateBinaryTree() const {
    auto* bt=new BinaryTree(root);
    return bt;
}

/*
 * A << operátor kinyomtatja a hármas fa tartalmát.
 */
std::ostream &operator<<(std::ostream &os, const TernaryTree &tt) {
    os<<tt.dumpTree();
    return os;
}

/*
 * A metódus dumpolja a tárolt hármas fát a feladatkiírásban leírtak szerint
 */
std::string TernaryTree::dumpTree() const{
    std::stringstream o;
    _preorder(root,o);
    return o.str();
}

void TernaryTree::_destroy(TernaryNode *n){
    if(n!=nullptr){
        _destroy(n->left);
        _destroy(n->middle);
        _destroy(n->right);
        delete n;
    }
}

TernaryNode* TernaryTree::_copyOf(TernaryNode* n, TernaryNode* p){
    if(n==nullptr) return nullptr;
    auto* x=new TernaryNode(n->value, p);
    x->left= _copyOf(n->left, x);
    x->middle= _copyOf(n->middle, x);
    x->right= _copyOf(n->right, x);
    return x;
}

std::ostream& TernaryTree::_preorder(TernaryNode* i, std::ostream& o) const{
    if (i == nullptr) o<<"(-";
    else {
        o<<"("<<i->value;
        if(i->left||i->middle||i->right){
            _preorder(i->left, o);
            _preorder(i->middle, o);
            _preorder(i->right, o);
        }
    }
    o<<")";
    return o;
}
