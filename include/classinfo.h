/**
 *  ClassInfo.h
 *
 *  Internal class that is constructed by the library and that contains
 *  the information about a class, including its name.
 * 
 *  Users of the PHP-CPP libraries are not supposed to interact with
 *  this class, or instantiate objects of this class.
 *  
 *  @author Emiel Bruijntjes <emiel.bruijntjes@copernica.com>
 *  @copyright 2013 Copernica BV
 */

/**
 *  Forward declarations
 */
struct _zend_class_entry;

/**
 *  Namespace
 */
namespace Php {

/**
 *  Virtual base class of the classInfo
 * 
 *  We need this virtual base class to store pointers to class objects,
 *  without knowing in advance what sort of object they will hold
 */
class _ClassInfo
{
public:
    /**
     *  Constructor
     *  @param  name
     */
    _ClassInfo(const char *name) : _name(name), _entry(NULL) {}
    
    /**
     *  Destructor
     */
    virtual ~_ClassInfo() {}

    /**
     *  Initialize the class
     */
    void initialize();

private:
    /**
     *  Class name
     *  @var    string
     */
    std::string _name;

    /** 
     *  The class entry
     *  @var    zend_class_entry
     */
    struct _zend_class_entry *_entry;

};

/**
 *  Class definition
 */
template <typename T>
class ClassInfo : public _ClassInfo
{
public:
    /**
     *  Constructor
     *  @param  name        Name of the class
     *  @param  type        The class type
     */
    ClassInfo(const char *name, const Class<T> &type) : _ClassInfo(name), _type(type)
    {
    }

    /**
     *  Destructor
     */
    virtual ~ClassInfo() {}


private:
    /**
     *  The class object
     *  @var    Class
     */
    Class<T> _type;

};
    
/**
 *  End of namespace
 */
}

