// Example: Building a Data Collection App on top of TPT
// src/app/AppEngine.h

#pragma once
#include "gui/interface/Window.h"
#include "simulation/Simulation.h"
#include <memory>
#include <vector>

class DataCollectionPanel;
class AnalysisWindow;

class AppEngine {
private:
    Simulation* sim;
    std::unique_ptr<DataCollectionPanel> dataPanel;
    std::unique_ptr<AnalysisWindow> analysisWindow;
    
    // Data collection
    struct SimulationData {
        int tick;
        int particleCount;
        float avgTemperature;
        float avgPressure;
        int explosionEvents;
    };
    std::vector<SimulationData> collectedData;
    
    bool isRecording = false;
    int recordingInterval = 10; // Every 10 ticks
    
public:
    static AppEngine& Ref();
    
    void Initialize(Simulation* simulation);
    void Shutdown();
    
    // Called from TPT's main loop
    void PreTick();
    void PostTick();
    void Draw();
    void HandleEvent(SDL_Event& event);
    
    // Data collection interface
    void StartRecording();
    void StopRecording();
    void ExportData(const String& filename);
    void ClearData();
    
    // Custom functionality
    void AddCustomElement();
    void SetupCustomUI();
    
    // Getters
    bool IsRecording() const { return isRecording; }
    const std::vector<SimulationData>& GetData() const { return collectedData; }
};

// Usage in main.cpp:
/*
int main(int argc, char* argv[]) {
    // Initialize TPT normally
    auto result = TPTMain(argc, argv);
    
    // Initialize your app
    AppEngine::Ref().Initialize(globalSim);
    
    // TPT handles the rest - your app hooks in automatically
    return result;
}
*/
