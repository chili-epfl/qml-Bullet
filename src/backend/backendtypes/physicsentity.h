#ifndef PhysicsENTITY_H
#define PhysicsENTITY_H
#include <qtphysicsunofficial_global.h>


namespace Physics {

class PhysicsManager;
class  QTPHYSICSUNOFFICIAL_EXPORT PhysicsEntity : public Qt3DCore::QBackendNode
{
public:
    explicit PhysicsEntity();
    ~PhysicsEntity();

    QString objectName(){return m_objectName;}

    PhysicsEntity* parent();
    Qt3DCore::QNodeId parentId()  { return m_parentId; }

    void addChildId(Qt3DCore::QNodeId childId);
    void removeChildId(Qt3DCore::QNodeId childId);

    const QSet<Qt3DCore::QNodeId>& childrenIds()  { return m_childrenId; }

    void setParentEntity(Qt3DCore::QNodeId parentId);

    void addComponent(const QMetaObject* type, Qt3DCore::QNodeId id);
    void removeComponent(Qt3DCore::QNodeId componentId);

    void setManager(PhysicsManager *manager);

    Qt3DCore::QNodeId geometry_renderer(){return m_geometry_renderer;}
    Qt3DCore::QNodeId transform(){return m_transform;}
    Qt3DCore::QNodeId physicsBodyInfo(){return m_physicsBodyInfo;}
    Qt3DCore::QNodeId physicsWorldInfo(){return m_physicsWorldInfo;}

    bool isEnabled(){return m_enabled;}

protected:
    void sceneChangeEvent(const Qt3DCore::QSceneChangePtr &) Q_DECL_OVERRIDE;
private:
    void initializeFromPeer(const Qt3DCore::QNodeCreatedChangeBasePtr &change) Q_DECL_OVERRIDE;

    Qt3DCore::QNodeId m_parentId;
    QSet<Qt3DCore::QNodeId > m_childrenId;
    bool m_enabled;
    QString m_objectName;

    Qt3DCore::QNodeId m_transform;
    Qt3DCore::QNodeId m_geometry_renderer;
    Qt3DCore::QNodeId m_physicsBodyInfo;

    Qt3DCore::QNodeId m_physicsWorldInfo;

    PhysicsManager* m_manager;

};


class QTPHYSICSUNOFFICIAL_EXPORT  PhysicsEntityFunctor : public Qt3DCore::QBackendNodeMapper
{
public:
    explicit PhysicsEntityFunctor(PhysicsManager* manager);
    Qt3DCore::QBackendNode *create(const Qt3DCore::QNodeCreatedChangeBasePtr &change) const Q_DECL_OVERRIDE;
    Qt3DCore::QBackendNode *get(Qt3DCore::QNodeId id) const Q_DECL_OVERRIDE;
    void destroy(Qt3DCore::QNodeId id) const Q_DECL_OVERRIDE;
private:
    PhysicsManager* m_manager;
};

}



#endif // PhysicsENTITYFUNCTOR_H
