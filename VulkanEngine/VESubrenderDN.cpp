/**
* The Vienna Vulkan Engine
*
* (c) bei Helmut Hlavacs, University of Vienna
*
*/


#include "VEInclude.h"


namespace ve {

	/**
	* \brief Initialize the subrenderer
	*
	* Create descriptor set layout, pipeline layout and the PSO
	*
	*/
	void VESubrenderDN::initSubrenderer() {

		VESubrender::initSubrenderer();

		//per object resources, set 0
		vh::vhRenderCreateDescriptorSetLayout(getRendererForwardPointer()->getDevice(),
			{ VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER },
			{ VK_SHADER_STAGE_VERTEX_BIT,		 VK_SHADER_STAGE_FRAGMENT_BIT,				VK_SHADER_STAGE_FRAGMENT_BIT },
		&m_descriptorSetLayout);

		vh::vhPipeCreateGraphicsPipelineLayout(getRendererForwardPointer()->getDevice(),
			{ m_descriptorSetLayout, getRendererForwardPointer()->getDescriptorSetLayoutPerFrame(), getRendererForwardPointer()->getDescriptorSetLayoutShadow() },
			&m_pipelineLayout);

		vh::vhPipeCreateGraphicsPipeline(getRendererForwardPointer()->getDevice(),
			"shader/DN/vert.spv", "shader/DN/frag.spv",
			getRendererForwardPointer()->getSwapChainExtent(),
			m_pipelineLayout, getRendererForwardPointer()->getRenderPass(),
			&m_pipeline);
	}


	/**
	* \brief Add an entity to the subrenderer
	*
	* Create a UBO for this entity, a descriptor set per swapchain image, and update the descriptor sets
	*
	*/
	void VESubrenderDN::addEntity(VEEntity *pEntity) {
		VESubrender::addEntity(pEntity);

		vh::vhBufCreateUniformBuffers(getRendererForwardPointer()->getVmaAllocator(),
			(uint32_t)getRendererForwardPointer()->getSwapChainNumber(),
			(uint32_t)sizeof(veUBOPerObject),
			pEntity->m_uniformBuffers, pEntity->m_uniformBuffersAllocation);

		vh::vhRenderCreateDescriptorSets(getRendererForwardPointer()->getDevice(),
			(uint32_t)getRendererForwardPointer()->getSwapChainNumber(),
			getDescriptorSetLayout(),
			getRendererForwardPointer()->getDescriptorPool(),
			pEntity->m_descriptorSets);

		for (uint32_t i = 0; i < pEntity->m_descriptorSets.size(); i++) {
			vh::vhRenderUpdateDescriptorSet(getRendererForwardPointer()->getDevice(),
				pEntity->m_descriptorSets[i],
				{ pEntity->m_uniformBuffers[i], VK_NULL_HANDLE, VK_NULL_HANDLE }, //UBOs
				{ sizeof(veUBOPerObject),   0,              0 },	//UBO sizes
				{ VK_NULL_HANDLE, pEntity->m_pMaterial->mapDiffuse->m_imageView, pEntity->m_pMaterial->mapNormal->m_imageView },	//textureImageViews
				{ VK_NULL_HANDLE, pEntity->m_pMaterial->mapDiffuse->m_sampler,   pEntity->m_pMaterial->mapNormal->m_sampler }	//samplers
			);
		}
	}
}


