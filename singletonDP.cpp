#include <iostream>
#include <string>
#include <map>
#include <mutex>

class ConfigurationManager {
private:
    static ConfigurationManager* instance;
    static std::mutex mutex_;
    std::map<std::string, std::string> settings;

    // Private constructor to prevent instantiation
    ConfigurationManager() {
        std::cout << "Configuration Manager instance created.\n";
        // Imagine loading configurations from a file or environment here
        settings["app_name"] = "MyApp";
        settings["version"] = "1.0";
        settings["max_users"] = "100";
    }

    // Delete copy constructor and assignment operator
    ConfigurationManager(const ConfigurationManager&) = delete;
    ConfigurationManager& operator=(const ConfigurationManager&) = delete;

public:
    // Static method to get the single instance
    static ConfigurationManager* getInstance() {
        if (instance == nullptr) {
            std::lock_guard<std::mutex> lock(mutex_);
            if (instance == nullptr) {
                instance = new ConfigurationManager();
            }
        }
        return instance;
    }

    // Method to get a configuration value
    std::string getValue(const std::string& key) {
        return settings[key];
    }

    // Method to set a configuration value
    void setValue(const std::string& key, const std::string& value) {
        settings[key] = value;
    }

    // Static method to delete the instance
    static void deleteInstance() {
        if (instance != nullptr) {
            delete instance;
            instance = nullptr;
            std::cout << "Configuration Manager instance deleted.\n";
        }
    }

    // print the settings
    void printSettings() {
        for (const auto& setting : settings) {
            std::cout << setting.first << ": " << setting.second << std::endl;
        }
    }
};

// Initialize static members
ConfigurationManager* ConfigurationManager::instance = nullptr;
std::mutex ConfigurationManager::mutex_;

int main() {
    // Access the configuration manager and retrieve a setting
    ConfigurationManager* configManager = ConfigurationManager::getInstance();
    configManager->printSettings();     // print the settings

    // Change a setting
    configManager->setValue("max_users", "200");
    std::cout << "------------------\nChange the Max Users\n";
    std::cout << "Max Users: " << configManager->getValue("max_users") << std::endl;

    // Access the configuration manager again to verify it's the same instance
    ConfigurationManager* anotherConfigManager = ConfigurationManager::getInstance();
    // print the settings
    std::cout << "============================================\n";
    std::cout << "Another Config Manager: \n";
    anotherConfigManager->printSettings();

    // Delete the instance
    ConfigurationManager::deleteInstance();

    return 0;
}
