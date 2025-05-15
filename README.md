My cmake template that uses CPM as package management. Implemented Spdlog, SDL3 and ImGui. Will change to Vulkan soon...


## .zprofile
```
# vulkan setup
export VULKAN_ROOT_LOCATION="$HOME/VulkanSDK/"
export VULKAN_SDK_VERSION="1.4.309.0"
export VULKAN_SDK="$VULKAN_ROOT_LOCATION/$VULKAN_SDK_VERSION/macOS"
export VK_ICD_FILENAME="$VULKAN_SDK/share/vulkan/icd.d/MoltenVK_icd.json"
export VK_LAYER_PATH="$VULKAN_SDK/share/vulkan/explicit_layer.d"
export PATH="$VULKAN_SDK/bin:$PATH"
```
