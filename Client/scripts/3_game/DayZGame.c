// modded class DayZGame
// {
//     protected ref CrateSettings m_SLCConfig;
//     protected ref KeyCardSettings m_KeyCardCofig;
    
//     void DayZGame()
// 	{
//         GetRPCManager().AddRPC( "KeycardCrates", "SLCClientActions", this, SingleplayerExecutionType.Both );
//     }

//     void SLCClientActions( CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target )
// 	{	
//         Param2<CrateSettings, KeyCardSettings> dataConfig;
//         if(!ctx.Read(dataConfig))
//             return;
//         SetSpawnableCrateConfig(dataConfig.param1, dataConfig.param2);
// 	}

//     CrateSettings GetSpawnableCrateConfig()
//     {
//         if (!m_SLCConfig && !GetGame().IsClient())
//         {
//             m_SLCConfig = new CrateSettings();
//             m_SLCConfig.Load();
//         }
//         else if(!m_SLCConfig && GetGame().IsClient())
//         {
//             return null;
//         }
//         return m_SLCConfig.GetInstance();
//     }

//     KeyCardSettings GetKeyCardManager().GetConfig()
//     {
//         if (!m_KeyCardCofig && !GetGame().IsClient())
//         {
//             m_KeyCardCofig = new KeyCardSettings();
//             m_KeyCardCofig.Load();
//         }
//         else if(!m_KeyCardCofig && GetGame().IsClient())
//         {
//             return null;
//         }
//         return m_KeyCardCofig.GetInstance();
//     }

//     void SetSpawnableCrateConfig(CrateSettings config, KeyCardSettings kcConfig)
//     {
//         m_SLCConfig = config;
//         m_KeyCardCofig = kcConfig;
//         // if (GetGame().IsClient())
//         //     ClientSetSpawnableCrateConfig(config);
//         // else
//         //     ServerSetSpawnableCrateConfig(config);
//     }

//     // void ServerSetSpawnableCrateConfig(CrateSettings config)
//     // {
//     //     if(GetGame().IsClient())
//     //     {
//     //         Error("ERROR: ServerSetSpawnableCrateConfig can only be called on server");
//     //         return;
//     //     }
//     //     m_SLCConfig = config;
//     // }

//     // void ClientSetSpawnableCrateConfig(CrateSettings config)
//     // {
//     //     if(!GetGame().IsClient())
//     //     {
//     //         Error("ERROR: ClientSetSpawnableCrateConfig can only be called on client");
//     //         return;
//     //     }

//     //     m_SLCConfig = config;
//     // }
// };
