## ZIAPI
Une version plus jolie arrivera un jour...

Voici un exemple de process pour le Core et les modules du Zia. Le "code" est vonlontairement simplifié et techniquement faux (par exemple pour le json) pour pouvoir expliquer le concept. Il est possible de modifier le process pour pouvoir par exemple créer un Core qui gère plusieurs Network et donc plusieurs listes de modules Http.

##### Lancer le Zia et demander en ligne de commande de charger un fichier de config.
On obtient:

    api::JsonValue config;

##### Grâce à la config, charger le module logger
On obtient:

    api::module::ALogger *logger;
    logger->setConfig(config["logger"]);

##### Grâce à la config, charger les modules http.
On obtient:

    std::vector<api::module::AHttp *> httpModules;

##### Pour chaque module Http:

    httpModules[i]->setLogger(logger);
    httpModules[i]->setConfig(config["http"][i]);

##### Grâce à la config, charger le module network:
    api::module::ANetwork *network;
    network->setLogger(logger);
    network->setConfig(config["network"]);
    network->setModules(httpModules);

##### En ligne de commande, on peut lancer le network
    network->startServing(); (le thread se lance dans la fonction startServing)


Le network va alors initialiser le serveur (socket, bind, listen) et accepter les connexion entrantes.
Pour chaque accepte, il va créer une ISocket * qui permettra de recevoir en envoyer des paquets et lancer un thread:
    
    {
        api::module::AHttp::Connection conn{new MyRequest(...), new MyResponse(...), socket}
        while (serverRunning && socket->isOpen()) {
            conn.request->clear();
            conn.response->clear();
            for (auto &module: httpModules) {
                if (!module->handle(conn)) {
                    conn.socket->closeSocket();
                    break;
                }
            }
        }
        if (conn.socket->isOpen())
            conn.socket->closeSocket();
        delete conn.request;
        delete conn.response;
        delete conn.socket;
    }
Chaque Module va ainsi pouvoir lire/écrire la requête ou la réponse et envoyer ou recevoir des paquets.

##### On peut à tout moment arrêter le module Network ou reload la config en ligne de commande
