//
// Created by Morten Nobel Jørgensen on 2018-11-06.
//

#include "GameObject.hpp"
#include "Transform.hpp"


GameObject::GameObject(std::string name_, Scene* scene_)
        :name(name_), scene(scene_)
{
    addComponent<Transform>();
}

GameObject::~GameObject() {
}

void GameObject::setName(const std::string &name) {
    GameObject::name = name;
}


std::string GameObject::getName() {
    return name;
}

bool GameObject::removeComponent(std::shared_ptr<Component> ptr) {
    for (auto iter = components.begin();iter != components.end(); iter++){
        if (*iter == ptr){
            components.erase(iter);
            return true;
        }
    }
    return false;
}

const std::vector<std::shared_ptr<Component>> &GameObject::getComponents() {
    return components;
}

Scene *GameObject::getScene() {
    return scene;
}
