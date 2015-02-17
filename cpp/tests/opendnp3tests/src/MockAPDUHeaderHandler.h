/**
 * Licensed to Green Energy Corp (www.greenenergycorp.com) under one or
 * more contributor license agreements. See the NOTICE file distributed
 * with this work for additional information regarding copyright ownership.
 * Green Energy Corp licenses this file to you under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except in
 * compliance with the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * This project was forked on 01/01/2013 by Automatak, LLC and modifications
 * may have been made to this file. Automatak, LLC licenses these modifications
 * to you under the terms of the License.
 */
#ifndef __MOCK_APDU_HEADER_HANDLER_H_
#define __MOCK_APDU_HEADER_HANDLER_H_

#include <opendnp3/app/parsing/APDUHandlerBase.h>

#include "LogTester.h"

#include <vector>

namespace opendnp3
{

class MockApduHeaderHandler : public IAPDUHandler, public LogTester
{
public:

	MockApduHeaderHandler()		
	{}

	virtual void AllObjects(const HeaderRecord& record) override
	{
		records.push_back(record);		
	}

	virtual void OnRangeRequest(const HeaderRecord& record, const Range& range) override
	{
		records.push_back(record);		
	}

	virtual void OnCountRequest(const HeaderRecord& record, uint16_t count) override
	{
		records.push_back(record);		
	}

	virtual void OnRange(const HeaderRecord& record, const IterableBuffer<IndexedValue<IINValue, uint16_t>>& meas) override
	{
		records.push_back(record);
		meas.foreach([&](const IndexedValue<IINValue, uint16_t>& v)
		{
			iinBits.push_back(v);
		});		
	}

	virtual void OnCountOf(const HeaderRecord& record, const IterableBuffer<Group50Var1>& times) override
	{
		records.push_back(record);		
	}

	virtual void OnCountOf(const HeaderRecord& record, const IterableBuffer<Group51Var1>& times) override
	{
		records.push_back(record);		
	}

	virtual void OnCountOf(const HeaderRecord& record, const IterableBuffer<Group51Var2>& times) override
	{
		records.push_back(record);		
	}

	virtual void OnCountOf(const HeaderRecord& record, const IterableBuffer<Group52Var2>& times) override
	{
		records.push_back(record);		
	}

	virtual void OnCountOf(const HeaderRecord& record, const IterableBuffer<Group120Var4>& values) override
	{
		records.push_back(record);
		values.foreach([this](const Group120Var4& v) {
			authStatusRequsts.push_back(v);
		});
		
	}

	virtual void OnRange(const HeaderRecord& record, const IterableBuffer<IndexedValue<Binary, uint16_t>>& meas) override
	{
		records.push_back(record);
		meas.foreach([this](const IndexedValue<Binary, uint16_t>& v)
		{
			staticBinaries.push_back(v);
		});		
	}

	virtual void OnRange(const HeaderRecord& record, const IterableBuffer<IndexedValue<DoubleBitBinary, uint16_t>>& meas) override
	{
		records.push_back(record);
		meas.foreach([this](const IndexedValue<DoubleBitBinary, uint16_t>& v)
		{
			staticDoubleBinaries.push_back(v);
		});		
	}

	virtual void OnRange(const HeaderRecord& record, const IterableBuffer<IndexedValue<BinaryOutputStatus, uint16_t>>& meas) override
	{
		records.push_back(record);
		meas.foreach([this](const IndexedValue<BinaryOutputStatus, uint16_t>& v)
		{
			staticControlStatii.push_back(v);
		});		
	}

	virtual void OnRange(const HeaderRecord& record, const IterableBuffer<IndexedValue<Counter, uint16_t>>& meas) override
	{
		records.push_back(record);
		meas.foreach([this](const IndexedValue<Counter, uint16_t>& v)
		{
			staticCounters.push_back(v);
		});		
	}

	virtual void OnRange(const HeaderRecord& record, const IterableBuffer<IndexedValue<FrozenCounter, uint16_t>>& meas) override
	{
		records.push_back(record);
		meas.foreach([this](const IndexedValue<FrozenCounter, uint16_t>& v)
		{
			staticFrozenCounters.push_back(v);
		});
	}

	virtual void OnRange(const HeaderRecord& record, const IterableBuffer<IndexedValue<Analog, uint16_t>>& meas)  override
	{
		records.push_back(record);
		meas.foreach([this](const IndexedValue<Analog, uint16_t>& v)
		{
			eventAnalogs.push_back(v);
		});		
	}

	virtual void OnRange(const HeaderRecord& record, const IterableBuffer<IndexedValue<AnalogOutputStatus, uint16_t>>& meas) override
	{
		records.push_back(record);
		meas.foreach([this](const IndexedValue<AnalogOutputStatus, uint16_t>& v)
		{
			staticSetpointStatii.push_back(v);
		});		
	}

	virtual void OnRange(const HeaderRecord& record, const IterableBuffer<IndexedValue<OctetString, uint16_t>>& meas) override
	{
		records.push_back(record);
		meas.foreach([this](const IndexedValue<OctetString, uint16_t>& v)
		{
			rangedOctets.push_back(v);
		});		
	}

	virtual void OnRange(const HeaderRecord& record, const IterableBuffer<IndexedValue<BinaryCommandEvent, uint16_t>>& meas) override
	{
		records.push_back(record);
		meas.foreach([this](const IndexedValue<BinaryCommandEvent, uint16_t>& v)
		{
			binaryCommandEvents.push_back(v);
		});		
	}

	virtual void OnRange(const HeaderRecord& record, const IterableBuffer<IndexedValue<AnalogCommandEvent, uint16_t>>& meas) override
	{
		records.push_back(record);
		meas.foreach([this](const IndexedValue<AnalogCommandEvent, uint16_t>& v)
		{
			analogCommandEvents.push_back(v);
		});		
	}

	virtual void OnRange(const HeaderRecord& record, const IterableBuffer<IndexedValue<TimeAndInterval, uint16_t>>& meas) override
	{
		records.push_back(record);
	}

	virtual void OnIndexPrefix(const HeaderRecord& record, const IterableBuffer<IndexedValue<Binary, uint16_t>>& meas) override
	{
		records.push_back(record);
		meas.foreach([this](const IndexedValue<Binary, uint16_t>& v)
		{
			eventBinaries.push_back(v);
		});		
	}

	virtual void OnIndexPrefix(const HeaderRecord& record, const IterableBuffer<IndexedValue<DoubleBitBinary, uint16_t>>& meas) override
	{
		records.push_back(record);
		meas.foreach([&](const IndexedValue<DoubleBitBinary, uint16_t>& v)
		{
			eventDoubleBinaries.push_back(v);
		});		
	}

	virtual void OnIndexPrefix(const HeaderRecord& record, const IterableBuffer<IndexedValue<Counter, uint16_t>>& meas)  override
	{
		records.push_back(record);
		meas.foreach([&](const IndexedValue<Counter, uint16_t>& v)
		{
			eventCounters.push_back(v);
		});		
	}

	virtual void OnIndexPrefix(const HeaderRecord& record, const IterableBuffer<IndexedValue<FrozenCounter, uint16_t>>& meas)  override
	{
		records.push_back(record);
		meas.foreach([&](const IndexedValue<FrozenCounter, uint16_t>& v)
		{
			eventFrozenCounters.push_back(v);
		});
	}

	virtual void OnIndexPrefix(const HeaderRecord& record, const IterableBuffer<IndexedValue<Analog, uint16_t>>& meas)  override
	{
		records.push_back(record);
		meas.foreach([&](const IndexedValue<Analog, uint16_t>& v)
		{
			eventAnalogs.push_back(v);
		});		
	}

	virtual void OnIndexPrefix(const HeaderRecord& record, const IterableBuffer<IndexedValue<OctetString, uint16_t>>& meas) override
	{
		records.push_back(record);
		meas.foreach([&](const IndexedValue<OctetString, uint16_t>& v)
		{
			indexPrefixedOctets.push_back(v);
		});		
	}

	virtual void OnIndexPrefix(const HeaderRecord& record, const IterableBuffer<IndexedValue<BinaryCommandEvent, uint16_t>>& meas) override
	{
		records.push_back(record);
		meas.foreach([&](const IndexedValue<BinaryCommandEvent, uint16_t>& v)
		{
			binaryCommandEvents.push_back(v);
		});		
	}

	virtual void OnIndexPrefix(const HeaderRecord& record, const IterableBuffer<IndexedValue<AnalogCommandEvent, uint16_t>>& meas) override
	{
		records.push_back(record);
		meas.foreach([&](const IndexedValue<AnalogCommandEvent, uint16_t>& v)
		{
			analogCommandEvents.push_back(v);
		});		
	}

	virtual void OnIndexPrefix(const HeaderRecord& record, const IterableBuffer<IndexedValue<ControlRelayOutputBlock, uint16_t>>& meas) override
	{
		records.push_back(record);
		meas.foreach([&](const IndexedValue<ControlRelayOutputBlock, uint16_t>& v)
		{
			crobRequests.push_back(v);
		});		
	}

	virtual void OnIndexPrefix(const HeaderRecord& record, const IterableBuffer<IndexedValue<AnalogOutputInt16, uint16_t>>& meas) override
	{
		records.push_back(record);
		meas.foreach([&](const IndexedValue<AnalogOutputInt16, uint16_t>& v)
		{
			aoInt16Requests.push_back(v);
		});		
	}

	virtual void OnIndexPrefix(const HeaderRecord& record, const IterableBuffer<IndexedValue<AnalogOutputInt32, uint16_t>>& meas) override
	{
		records.push_back(record);
		meas.foreach([&](const IndexedValue<AnalogOutputInt32, uint16_t>& v)
		{
			aoInt32Requests.push_back(v);
		});		
	}

	virtual void OnIndexPrefix(const HeaderRecord& record, const IterableBuffer<IndexedValue<AnalogOutputFloat32, uint16_t>>& meas) override
	{
		records.push_back(record);
		meas.foreach([&](const IndexedValue<AnalogOutputFloat32, uint16_t>& v)
		{
			aoFloat32Requests.push_back(v);
		});		
	}

	virtual void OnIndexPrefix(const HeaderRecord& record, const IterableBuffer<IndexedValue<AnalogOutputDouble64, uint16_t>>& meas) override
	{
		records.push_back(record);
		meas.foreach([&](const IndexedValue<AnalogOutputDouble64, uint16_t>& v)
		{
			aoDouble64Requests.push_back(v);
		});		
	}

	virtual void OnIndexPrefix(const HeaderRecord& record, const IterableBuffer<IndexedValue<BinaryOutputStatus, uint16_t>>& meas) override
	{
		records.push_back(record);
	}

	virtual void OnIndexPrefix(const HeaderRecord& record, const IterableBuffer<IndexedValue<AnalogOutputStatus, uint16_t>>& meas) override
	{
		records.push_back(record);
	}

	virtual void OnIndexPrefix(const HeaderRecord& record, const IterableBuffer<IndexedValue<TimeAndInterval, uint16_t>>& meas) override
	{
		records.push_back(record);
	}

	virtual void OnFreeFormat(const HeaderRecord& record, const Group120Var1& value) override
	{
		records.push_back(record);
		authChallenges.push_back(value);
	}

	virtual void OnFreeFormat(const HeaderRecord& record, const Group120Var2& value) override
	{
		records.push_back(record);
		authReplys.push_back(value);
	}

	virtual void OnFreeFormat(const HeaderRecord& record, const Group120Var5& value) override
	{
		records.push_back(record);
		authKeyStatusResponses.push_back(value);
	}

	virtual void OnFreeFormat(const HeaderRecord& record, const Group120Var6& value) override
	{
		records.push_back(record);
		authChanges.push_back(value);
	}

	std::vector<HeaderRecord> records;

	std::vector<Group120Var1> authChallenges;
	std::vector<Group120Var2> authReplys;
	std::vector<Group120Var4> authStatusRequsts;
	std::vector<Group120Var5> authKeyStatusResponses;
	std::vector<Group120Var6> authChanges;

	std::vector<IndexedValue<IINValue, uint16_t>> iinBits;

	std::vector<IndexedValue<Binary, uint16_t>> eventBinaries;
	std::vector<IndexedValue<Binary, uint16_t>> staticBinaries;

	std::vector<IndexedValue<DoubleBitBinary, uint16_t>> eventDoubleBinaries;
	std::vector<IndexedValue<DoubleBitBinary, uint16_t>> staticDoubleBinaries;

	std::vector<IndexedValue<BinaryOutputStatus, uint16_t>> staticControlStatii;

	std::vector<IndexedValue<Counter, uint16_t>> eventCounters;
	std::vector<IndexedValue<Counter, uint16_t>> staticCounters;

	std::vector<IndexedValue<FrozenCounter, uint16_t>> eventFrozenCounters;
	std::vector<IndexedValue<FrozenCounter, uint16_t>> staticFrozenCounters;

	std::vector<IndexedValue<Analog, uint16_t>> eventAnalogs;
	std::vector<IndexedValue<Analog, uint16_t>> staticAnalogs;

	std::vector<IndexedValue<AnalogOutputStatus, uint16_t>> staticSetpointStatii;

	std::vector<IndexedValue<ControlRelayOutputBlock, uint16_t>> crobRequests;

	std::vector<IndexedValue<AnalogOutputInt16, uint16_t>> aoInt16Requests;
	std::vector<IndexedValue<AnalogOutputInt32, uint16_t>> aoInt32Requests;
	std::vector<IndexedValue<AnalogOutputFloat32, uint16_t>> aoFloat32Requests;
	std::vector<IndexedValue<AnalogOutputDouble64, uint16_t>> aoDouble64Requests;

	std::vector<IndexedValue<OctetString, uint16_t>> indexPrefixedOctets;
	std::vector<IndexedValue<OctetString, uint16_t>> rangedOctets;

	std::vector<IndexedValue<BinaryCommandEvent, uint16_t>> binaryCommandEvents;

	std::vector<IndexedValue<AnalogCommandEvent, uint16_t>> analogCommandEvents;
};

}

#endif
