#include "NetworkJoinTrigger.hpp"
#include "UnityEngine/GameObject.hpp"
#include "System/String.hpp"
#include "GlobalNamespace/PhotonNetworkController.hpp"
#include "GlobalNamespace/GorillaLevelScreen.hpp"

DEFINE_TYPE(GorillaUtils, NetworkJoinTrigger);

using namespace UnityEngine;

namespace GorillaUtils
{
    void NetworkJoinTrigger::ctor()
    {
        instance = this;
        makeSureThisIsDisabled = reinterpret_cast<Array<GameObject*>*>(il2cpp_functions::array_new(classof(GameObject*), 0));
        makeSureThisIsEnabled = reinterpret_cast<Array<GameObject*>*>(il2cpp_functions::array_new(classof(GameObject*), 0));
        gameModeName = Il2CppString::_get_Empty();
        photonNetworkController = GlobalNamespace::PhotonNetworkController::_get_instance();
        componentTarget = nullptr;

        joinScreens = reinterpret_cast<Array<GlobalNamespace::GorillaLevelScreen*>*>(il2cpp_functions::array_new(classof(GlobalNamespace::GorillaLevelScreen*), 0));
        leaveScreens = reinterpret_cast<Array<GlobalNamespace::GorillaLevelScreen*>*>(il2cpp_functions::array_new(classof(GlobalNamespace::GorillaLevelScreen*), 0));

        triggerBoxOnce = false;
    }

    NetworkJoinTrigger* NetworkJoinTrigger::get_instance()
    {
        if (!instance)
        {
            GameObject* obj = GameObject::New_ctor();
            instance = obj->AddComponent<NetworkJoinTrigger*>();
        }

        return instance;
    }

    void NetworkJoinTrigger::set_gameMode(std::string gameMode)
    {
        this->gameModeName = il2cpp_utils::newcsstr(gameMode);
    }
}