#ifndef INPUT_FILTER_PARAMETERS_H_
#define INPUT_FILTER_PARAMETERS_H_
/**
 * \file inputFilterParameters.h
 * \attention This file is automatically generated and should not be in general modified manually
 *
 * \date MMM DD, 20YY
 * \author autoGenerator
 * Generated from bufferFilters.xml
 */

#include "core/reflection/reflection.h"
#include "core/reflection/defaultSetter.h"
#include "core/reflection/printerVisitor.h"

/*
 *  Embed includes.
 */
/*
 *  Additional includes for Composite Types.
 */

// using namespace corecvs;

/*
 *  Additional includes for Pointer Types.
 */

// namespace corecvs {
// }
/*
 *  Additional includes for enum section.
 */
#include "core/xml/generated/inputType.h"

/**
 * \brief Input Filter Parameters 
 * Input Filter Parameters 
 **/
class InputFilterParameters : public corecvs::BaseReflection<InputFilterParameters>
{
public:
    enum FieldId {
        INPUT_TYPE_ID,
        INPUT_FILTER_PARAMETERS_FIELD_ID_NUM
    };

    /** Section with variables */

    /** 
     * \brief Input Type 
     * Input Type 
     */
    int mInputType;

    /** Static fields init function, this is used for "dynamic" field initialization */ 
    static int staticInit(corecvs::Reflection *toFill);

    static int relinkCompositeFields();

    /** Section with getters */
    const void *getPtrById(int fieldId) const
    {
        return (const unsigned char *)(this) + fields()[fieldId]->offset;
    }
    InputType::InputType inputType() const
    {
        return static_cast<InputType::InputType>(mInputType);
    }

    /** Section with setters */
    void setInputType(InputType::InputType inputType)
    {
        mInputType = inputType;
    }

    /** Section with embedded classes */
    /* visitor pattern - http://en.wikipedia.org/wiki/Visitor_pattern */
template<class VisitorType>
    void accept(VisitorType &visitor)
    {
        visitor.visit((int &)mInputType,          static_cast<const corecvs::EnumField *>(fields()[INPUT_TYPE_ID]));
    }

    InputFilterParameters()
    {
        corecvs::DefaultSetter setter;
        accept(setter);
    }

    InputFilterParameters(
          InputType::InputType inputType
    )
    {
        mInputType = inputType;
    }

    /** Exact match comparator **/ 
    bool operator ==(const InputFilterParameters &other) const 
    {
        if ( !(this->mInputType == other.mInputType)) return false;
        return true;
    }
    friend std::ostream& operator << (std::ostream &out, InputFilterParameters &toSave)
    {
        corecvs::PrinterVisitor printer(out);
        toSave.accept<corecvs::PrinterVisitor>(printer);
        return out;
    }

    void print ()
    {
        std::cout << *this;
    }
};
#endif  //INPUT_FILTER_PARAMETERS_H_
