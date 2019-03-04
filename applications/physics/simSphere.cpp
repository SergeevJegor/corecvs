#include "simSphere.h"

#include <mesh3DScene.h>

SimSphere::SimSphere()
{
}

void SimSphere::saveMesh(const std::string &name)
{
    cout<<"here"<<endl;
    Affine3DQ copterPos = Affine3DQ::Shift(10,10,10);

    //Mesh3DDecorated *mesh = new Mesh3DDecorated;
    Mesh3DScene *mesh = new Mesh3DScene;

    mesh->switchColor();

    mesh->mulTransform(copterPos);

    mesh->setColor(RGBColor::Red());
    mesh->addIcoSphere(coords, 2, 2);

    mesh->popTransform();

    mesh->dumpPLY(name+".ply");

    delete_safe(mesh);
}
