#include <vtkSmartPointer.h>
#include <vtkCubeAxesActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkCamera.h>
#include <vtkAxesActor.h>
#include <vtkProperty.h>

// Gerekli render modüllerini otomatik başlatmak için VTK AutoInit
#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2);  // OpenGL2 Rendering başlatılır
VTK_MODULE_INIT(vtkInteractionStyle); // Etkileşim stilleri başlatılır

VTK_MODULE_INIT(vtkRenderingFreeType);

int main() {
    // 1. Kamera nesnesini oluşturun
    vtkSmartPointer<vtkCamera> camera = vtkSmartPointer<vtkCamera>::New();
    camera->SetPosition(0, 0, 10); // Kamerayı uygun bir pozisyona yerleştirin
    camera->SetFocalPoint(0, 0, 0); // Görüş noktası
    camera->SetViewUp(0, 1, 0); // Kameranın üst yönü

    // 2. CubeAxesActor nesnesini oluşturun
    vtkSmartPointer<vtkCubeAxesActor> cubeAxesActor = vtkSmartPointer<vtkCubeAxesActor>::New();
    cubeAxesActor->SetCamera(camera); // Kamera nesnesini CubeAxesActor'a bağlayın

    // 3. Kamera ve aktörlerin görüntülenebilmesi için renderer oluşturun
    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(cubeAxesActor); // CubeAxesActor'ı renderer'a ekleyin

    // 4. RenderWindow ve interactor nesnelerini oluşturun
    vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
    renderWindow->AddRenderer(renderer); // Renderer'ı RenderWindow'a ekleyin

    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    renderWindowInteractor->SetRenderWindow(renderWindow); // RenderWindowInteractor'ı RenderWindow'a bağlayın

    // 5. Render işlemi
    renderWindow->Render(); // Render işlemi başlatılır
    renderWindowInteractor->Start(); // Kullanıcı etkileşimini başlatır

    return 0;
}
