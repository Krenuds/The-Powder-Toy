// Example: Custom UI Panel for data collection
// src/app/DataCollectionPanel.h

#pragma once
#include "gui/interface/Panel.h"
#include "gui/interface/Button.h"
#include "gui/interface/Label.h"
#include "gui/interface/Textbox.h"

class DataCollectionPanel : public ui::Panel {
private:
    ui::Button* startButton;
    ui::Button* stopButton;
    ui::Button* exportButton;
    ui::Button* clearButton;
    ui::Label* statusLabel;
    ui::Label* dataCountLabel;
    ui::Textbox* intervalTextbox;
    
public:
    DataCollectionPanel(Vec2<int> position, Vec2<int> size);
    virtual ~DataCollectionPanel();
    
    void OnInitialized() override;
    void OnTick(float dt) override;
    void OnDraw() override;
    
    // Button callbacks
    void OnStartClicked();
    void OnStopClicked();
    void OnExportClicked();
    void OnClearClicked();
    
    void UpdateStatus();
};

// Implementation would go in DataCollectionPanel.cpp
/*
DataCollectionPanel::DataCollectionPanel(Vec2<int> position, Vec2<int> size) 
    : Panel(position, size) {
    
    // Create buttons
    startButton = new ui::Button(Vec2<int>(10, 10), Vec2<int>(80, 20), "Start");
    stopButton = new ui::Button(Vec2<int>(100, 10), Vec2<int>(80, 20), "Stop");
    exportButton = new ui::Button(Vec2<int>(10, 40), Vec2<int>(80, 20), "Export");
    clearButton = new ui::Button(Vec2<int>(100, 40), Vec2<int>(80, 20), "Clear");
    
    // Create labels
    statusLabel = new ui::Label(Vec2<int>(10, 70), Vec2<int>(170, 15), "Status: Stopped");
    dataCountLabel = new ui::Label(Vec2<int>(10, 90), Vec2<int>(170, 15), "Data points: 0");
    
    // Create textbox for interval
    intervalTextbox = new ui::Textbox(Vec2<int>(10, 110), Vec2<int>(50, 20), "10");
    
    // Set up callbacks
    startButton->SetActionCallback({[this] { OnStartClicked(); }});
    stopButton->SetActionCallback({[this] { OnStopClicked(); }});
    exportButton->SetActionCallback({[this] { OnExportClicked(); }});
    clearButton->SetActionCallback({[this] { OnClearClicked(); }});
    
    // Add to panel
    AddComponent(startButton);
    AddComponent(stopButton);
    AddComponent(exportButton);
    AddComponent(clearButton);
    AddComponent(statusLabel);
    AddComponent(dataCountLabel);
    AddComponent(intervalTextbox);
}

void DataCollectionPanel::OnStartClicked() {
    AppEngine::Ref().StartRecording();
    UpdateStatus();
}

void DataCollectionPanel::OnStopClicked() {
    AppEngine::Ref().StopRecording();
    UpdateStatus();
}

void DataCollectionPanel::UpdateStatus() {
    auto& app = AppEngine::Ref();
    statusLabel->SetText(app.IsRecording() ? "Status: Recording" : "Status: Stopped");
    dataCountLabel->SetText("Data points: " + String::Build(app.GetData().size()));
}
*/
