/*
	This file is part of the Rendering library.
	Copyright (C) 2007-2012 Benjamin Eikel <benjamin@eikel.org>
	Copyright (C) 2007-2012 Claudius Jähn <claudius@uni-paderborn.de>
	Copyright (C) 2007-2012 Ralf Petring <ralf@petring.net>
	
	This library is subject to the terms of the Mozilla Public License, v. 2.0.
	You should have received a copy of the MPL along with this library; see the 
	file LICENSE. If not, you can obtain one at http://mozilla.org/MPL/2.0/.
*/
#ifndef RENDERING_MESHINDEXDATA_H
#define RENDERING_MESHINDEXDATA_H

#include "../BufferObject.h"
#include <cstddef>
#include <cstdint>
#include <vector>

namespace Rendering {

/*! IndexData-Class .
	Part of the Mesh implementation containing all index specific data of a mesh. */
class MeshIndexData {
	public:
		MeshIndexData();
		//! Copy all data from @p other
		MeshIndexData(const MeshIndexData & other);
		MeshIndexData(MeshIndexData &&) = default;

		~MeshIndexData() = default;

		MeshIndexData & operator=(const MeshIndexData &) = delete;
		MeshIndexData & operator=(MeshIndexData &&) = default;

		void swap(MeshIndexData & other);
		uint32_t getIndexCount()const						{	return indexCount;	}
		bool empty()const									{	return indexCount==0;	}

		// data
		void allocate(uint32_t count);
		void releaseLocalData();
		const uint32_t * data() const						{	return indexArray.data();	}
		uint32_t * data() 									{	return indexArray.data();	}
		std::size_t dataSize() const						{	return indexArray.size() * sizeof(uint32_t);	}
		void markAsChanged()								{  	dataChanged=true;	}
		bool hasChanged()const								{  	return dataChanged;	}
		bool hasLocalData()const							{  	return !indexArray.empty();	}

		const uint32_t & operator[](uint32_t index) const	{	return indexArray[index]; }
		uint32_t & operator[](uint32_t index) 				{	return indexArray[index]; }

		// index range
		inline uint32_t getMinIndex() const 				{   return minIndex;    }
		inline uint32_t getMaxIndex() const 				{   return maxIndex;    }
		/*! Recalculates the index range of the mesh.
			\note Should be called whenever the vertices are changed.	*/
		void updateIndexRange();

		// vbo
		inline bool isUploaded()const						{   return bufferObject.isValid();    }

		//! Call @a upload() with default usage hint.
		bool upload();
		/*! (internal) Create or update a VBO if hasChanged is set to true.
			hasChanged is set to false.	*/
		bool upload(uint32_t usageHint);
		/*! (internal) */
		bool download();
		void downloadTo(std::vector<uint32_t> & destination) const;
		/*! (internal) */
		void removeGlBuffer();
		/*! (internal) Draw the vertices referenced by the indices using the VBO or a VertexArray.
			Used by MeshDataStrategy::doDisplay(..) */
		void drawElements(bool useVBO,uint32_t drawMode,uint32_t startIndex,uint32_t numberOfIndices);

		/*! Swap the internal BufferObject.
			\note The local data is not changed!
			\note the size of the new buffer must be equal to that of the old one.
			\note Use only if you know what you are doing!	*/
		void _swapBufferObject(BufferObject & other)	{	bufferObject.swap(other);	}
	private:
		uint32_t indexCount;
		std::vector<uint32_t> indexArray;
		uint32_t minIndex;
		uint32_t maxIndex;
		BufferObject bufferObject;
		bool dataChanged;
};
}

#endif /* RENDERING_MESHINDEXDATA_H */
